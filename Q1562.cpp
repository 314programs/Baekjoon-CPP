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

int dp[105][10][1 << 10];
const int MOD = 1000000000;

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);
	
	int n;
	cin >> n;

	for(int i = 1; i <= 9; i++){
		dp[1][i][1 << i] = 1;
	}

	for(int i = 1; i <= n-1; i++){
		for(int j = 0; j <= 9; j++){
			for(int k = 0; k < (1 << 10); k++){
				if(dp[i][j][k] == 0){
					continue;
				}
				if(!(k & (1 << j))){
					continue;
				}
				if(j + 1 <= 9){
					dp[i+1][j+1][k | (1 << (j+1))] += dp[i][j][k];
					dp[i+1][j+1][k | (1 << (j+1))] %= MOD;
				}
				if(j - 1 >= 0){
					dp[i+1][j-1][k | (1 << (j-1))] += dp[i][j][k];
					dp[i+1][j-1][k | (1 << (j-1))] %= MOD;
				}
			}
		}
	}

	int ans = 0;
	for(int i = 0; i <= 9; i++){
		ans += dp[n][i][(1 << 10)-1];
		ans %= MOD;
	}
	cout << ans;

}
