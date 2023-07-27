//I FORGOT TO POST ON GITHUB OMG
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
int dp[200][1 << 14];

int solve(int num, int state){
	if(num == n*m && state == 0){
		return 1;
	}
	if(num >= n*m){
		return 0;
	}
	if(dp[num][state] != -1){
		return dp[num][state];
	}

	int &ans = dp[num][state];
	ans = 0;
	if(state & 1){
		ans = solve(num+1, state >> 1);
	}
	else{
		ans = solve(num+1, (state >> 1) | (1 << (m-1)));
		if((num % m) != (m-1) && (state & 2) == 0){
			ans += solve(num+2, state >> 2);
		}
	}
	ans %= 9901;
	return ans;

}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0);

}
