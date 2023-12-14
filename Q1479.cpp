#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

void setIO(string s = ""){
	if(s == "") return;
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

struct st{
	int cur;
	vector<int> lis_len;

	st(){
		cur = -1;
		lis_len = {0, 0, 0, 0};
	}
};

//idx, completed words, word idx, min/max
st dp[2505][2][16][16];
string s;
vector<string> lis;

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	cin >> s;
	int n = s.length();
	lis.resize(4);

	for(int i = 0; i < 4; i++){
		cin >> lis[i];
	}
	dp[0][0][0][0].cur = 0;
	dp[0][1][0][0].cur = 0;

	for(int idx = 0; idx < n; idx++){
		//Maximum or minimum?
		for(int m = 0; m < 2; m++){
			//Words completed?
			for(int comp = 0; comp < 16; comp++){
				//check previous continuation for words
				for(int pv = 0; pv < 16; pv++){
					if(dp[idx][m][comp][pv].cur == -1){
						continue;
					}


					//continuations that can be made
					for(int cur = 0; cur < 16; cur++){
						//Words that was started before must continue on by removing curs under a condition
						bool skip = false;
						for(int i = 0; i < 4; i++){
							if(!(comp & (1 << i)) && dp[idx][m][comp][pv].lis_len[i] > 0 && !(cur & (1 << i))){
								skip = true;
							} 
						}
						if(skip) continue;


						int next_comp = comp;
						int covered = false;
						vector<int> next_idx = {0, 0, 0, 0};
						bool impossible = false;

						for(int i = 0; i < 4; i++){
							//Word already complete or word not started
							if(comp & (1 << i)) continue;
							if(!(cur & (1 << i))) continue;

							int letter_idx = 0;
							//Word continued
							if((pv & (1 << i)) && (cur & (1 << i))){
								letter_idx = dp[idx][m][comp][pv].lis_len[i];
							}

							bool can = true;
							//Remove words that get discontinued ltr
							//Even if this applies, words might get discontinued ltr due to cur(the loop)
							if(letter_idx == 0){
								if(lis[i].length() + idx > n){
									can = false;
								}
								else{
									for(int j = 0; j < lis[i].length(); j++){
										if(lis[i][j] != s[j+idx]){
											can = false;
										}
									}
								}
							}
							
							//Check if the letter is the same
							if(can){
								letter_idx++;
								if(letter_idx >= lis[i].length()){
									next_comp |= (1 << i);
								}
								next_idx[i] = letter_idx;
								covered = true;
							}
							else{
								impossible = true;
							}
						}

						//If a word is impossible to make, than the current position should not exist
						if(impossible) continue;
						int next = -1;
						if(covered) next = dp[idx][m][comp][pv].cur + 1;
						else next = dp[idx][m][comp][pv].cur;


						//min
						if(m == 0){
							if(dp[idx+1][m][next_comp][cur].cur == -1 || dp[idx+1][m][next_comp][cur].cur >= next){
								dp[idx+1][m][next_comp][cur].cur = next;
								dp[idx+1][m][next_comp][cur].lis_len = next_idx;
							}
						}

						//max
						else{
							if(dp[idx+1][m][next_comp][cur].cur == -1 || dp[idx+1][m][next_comp][cur].cur < next){
								dp[idx+1][m][next_comp][cur].cur = next;
								dp[idx+1][m][next_comp][cur].lis_len = next_idx;
							}
						}
					}
				}
			}
		}
	}

	int mn = 2505;
	int mx = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < 16; j++){
			if(dp[i][0][15][j].cur != -1) mn = min(mn, dp[i][0][15][j].cur);
			if(dp[i][1][15][j].cur != -1) mx = max(mx, dp[i][1][15][j].cur);
		}
	}
	cout << mn << " " << mx << "\n";

}
