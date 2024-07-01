#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
//#define int long long 

void setIO(string s = ""){
    if(s == "") return;
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}

int u[3001];
int dp[3001][3001][2];
int n, m;

//memory test
int solve(int idx, int left, bool sleep){
	if(left == 0){
		return 0;
	}
	else if(idx >= n || n - idx < left){
		return -1e11;
	}

	if(dp[idx][left][sleep] >= 0){
		return dp[idx][left][sleep];
	}

	if(sleep){
		dp[idx][left][sleep] = max(solve(idx+1, left, false), solve(idx+1, left-1, true) + u[idx]);
	}
	else{
		dp[idx][left][sleep] = max(solve(idx+1, left, false), solve(idx+1, left-1, true));
	}
	return dp[idx][left][sleep];
}

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;
	memset(dp, -1, sizeof(dp));

	for(int i = 0; i < n; i++){
		cin >> u[i];
	}
	cout << solve(0, m, false);

}
