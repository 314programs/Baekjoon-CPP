//I did a DP???? ALONE???? PLAT 2???
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
int dp[260][1 << 11];
char a[25][25];

int solve(int num, int state){
	if(num == n*m && state == 0){
		return 0;
	}
	if(num >= n*m){
		return -10000000;
	}
	if(dp[num][state] != -1){
		return dp[num][state];
	}


	int &ans = dp[num][state];
	ans = 0;
	int r = num/m;
	int c = num%m;

	bitset<2> b(state);

	int next = 0;
	if(a[r+1][c] == '1'){
		next = 1 << (m-1);
		ans++;
	}

	if(state & 1){
		ans += solve(num+1, (state >> 1) | next);
	}
	else{
		ans += solve(num+1, (state >> 1) | next) + 1;

		if(c != m-1 && r != n-1){
			if((state & 2) == 0 && a[r+1][c] == '.' && a[r+1][c+1] == '.'){
				ans = max(ans, solve(num+2, (state >> 2) | (1 << (m-1)) | (1 << (m-2))) + 16);
			}
		}
	}
	return ans;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < m; j++){
			a[j][i] = s[j];
		}
	}
	swap(n, m);

	int cur_state = 0;
	int add_on = 0;
	for(int j = 0; j < m; j++){
		if(a[0][j] == '1'){
			cur_state |= (1 << j);
			add_on++;
		} 
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(0, cur_state) + add_on;

}
