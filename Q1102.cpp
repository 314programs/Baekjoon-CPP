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

int DP[1 << 16][17];

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	int n;
	cin >> n;
	int a[n][n];
	memset(DP, -1, sizeof(DP));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}

	string s;
	cin >> s;
	int p;
	cin >> p;

	int cur_state = 0;
	int cur_cnt = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'Y'){
			cur_state |= (1 << i);
			cur_cnt++;
		}
	}

	if(cur_cnt >= p){
		cout << 0;
	}
	else{
		DP[cur_state][cur_cnt] = 0;
		for(int i = cur_cnt; i <= p-1; i++){
			for(int state = cur_state; state < (1 << n); state++){
				if(DP[state][i] == -1) continue;

				for(int j = 0; j < n; j++){
					if(!(state & (1 << j))) continue;
					for(int k = 0; k < n; k++){
						if(state & (1 << k) || j == k) continue;
						int new_cost = DP[state][i] + a[j][k];
						if(DP[state | (1 << k)][i+1] == -1 || DP[state | (1 << k)][i+1] > new_cost){
							DP[state | (1 << k)][i+1] = new_cost;
						}
					}
				}
			}
		}

		int ans = -1;
		for(int state = cur_state; state < (1 << n); state++){
			if(DP[state][p] == -1) continue;
			if(ans == -1 || ans > DP[state][p]){
				ans = DP[state][p];
			}
		}
		cout << ans;

	}


}
