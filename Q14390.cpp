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

int n, m;
int DP[11][1 << 10];
char a[11][10];

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	memset(DP, -1, sizeof(DP));
	DP[0][0] = 0;

	for(int i = 1; i <= n; i++){
		for(int p_state = 0; p_state < (1 << m); p_state++){
			if(DP[i-1][p_state] == -1) continue;
			for(int state = 0; state < (1 << m); state++){
				int last = -10;
				int cnt = 0;

				for(int k = 0; k < m; k++){
					if(a[i][k] == '#'){
						continue;
					}

					if(state & (1 << k)){
						if(i-1 == 0) cnt++;
						else if(!(p_state & (1 << k))) cnt++;
						else if(a[i-1][k] == '#') cnt++;
					}
					else{
						if(k-1 != last){
							cnt++;
						}
						last = k;
					}
				}

				if(DP[i][state] == -1 ||  DP[i][state] > DP[i-1][p_state] + cnt){
					DP[i][state] = DP[i-1][p_state] + cnt;
				}
			}
		}
	}

	int ans = 1e9;
	for(int i = 0; i < (1 << m); i++){
		if(DP[n][i] == -1) continue;
		ans = min(DP[n][i], ans);
	}
	cout << ans;

}
