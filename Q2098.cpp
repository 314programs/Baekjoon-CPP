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

int a[16][16];
int dp[1 << 16][16];

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}

	for(int i = 0; i < (1 << n); i++){
		for(int j = 0; j < n; j++){
			dp[i][j] = 1e9;
		}
	}

	dp[1][0] = 0;
	for(int i = 0; i < (1 << n); i++){
		for(int j = 0; j < n; j++){
			if((1 << j) & i){
				for(int k = 0; k < n; k++){
					if(k != j && !(i & (1 << k)) && a[j][k]){
						dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + a[j][k]);
					}
				}
			}
		}
	}

	int ans = 1e9;
	for(int i = 1; i < n; i++){
		if(a[i][0]){
			ans = min(ans, a[i][0] + dp[(1 << n)-1][i]);
		}
	}
	cout << ans;


}
