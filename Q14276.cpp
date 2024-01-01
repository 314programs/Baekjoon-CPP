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

int n, m, k;
long long mod = 1000000007;
int DP[35][35][35][1 << 9];

int solve(int num, int road, int cur_connect, int state){
	if(num == n){
		if(road == 0 && state == 0) return 1;
		else return 0;
	}

	if(cur_connect == k){
		if((state & (1 << k)) == 0){
			return solve(num+1, road, 0, state << 1);
		}
		else{
			return 0;
		}
	}

	int &ans = DP[num][road][cur_connect][state];
	if(ans != -1){
		return ans;
	}

	ans = solve(num, road, cur_connect+1, state);
	if(num -(cur_connect+1) >= 0 && road > 0){
		ans += solve(num, road-1, cur_connect, state ^ 1 ^ (1 << (cur_connect+1)));
	}
	ans %= mod;
	return ans;

}


int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	
	cin >> n >> m >> k;

	memset(DP, -1, sizeof(DP));
	cout << solve(0, m, 0, 0);
}
