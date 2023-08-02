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

int a[3][1000];
int DP[1005][1005][1 << 3];
const int inf = 1e12;

//prev, next, new dominos placed
int states[11][3] = {
	{0, 0, 0},
	{1, 1, 1},
	{2, 2, 1},
	{4, 4, 1},
	{0, 3, 1},
	{0, 6, 1},
	{1, 7, 2},
	{4, 7, 2},
	{3, 3, 2},
	{6, 6, 2},
	{5, 5, 2}
};

int calc(int n, int cur){
	int ans = 0;
	if(n < 0 && cur != 0) return -inf;
	if(cur & 1) ans += a[0][n];
	if(cur & 2) ans += a[1][n];
	if(cur & 4) ans += a[2][n];
	return ans;
}

int solve(int row, int k, int state){
	if(row < 0){
		if(k == 0) return 0;
		return -inf;
	}
	if(k == 0) return 0;
	if(k < 0) return -inf;

	int &ans = DP[row][k][state];
	if(ans != -inf){
		return ans;
	}

	for(int i = 0; i < 11; i++){
		int prev = states[i][0];
		int cur = states[i][1];
		int cost = states[i][2];
		if(cur & state) continue;
		ans = max(ans, calc(row, cur) + calc(row-1, prev) + solve(row-1, k-cost, prev));
	}
	return ans;

}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	int n, m, k;
	cin >> n >> k;
	m = 3;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[j][i];
		}
	}
	fill(&DP[0][0][0], &DP[1005][0][0], -inf);
	cout << solve(n-1, k, 0);

}
