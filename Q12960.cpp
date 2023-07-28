//WHY DOES THIS WORK???
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
int dp[260][1 << 5];
char a[50][50];

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

	int new_r = (num+m+1)/m;
	int new_c = (num+m+1)%m;
	int next = 0;
	if(a[new_r][new_c] == 'X'){
		next = 1 << m;
	}

	bitset<4> b(state);
	ans = solve(num+1, (state >> 1) | next);

	if((state & 1) == 0 && a[r][c] == '.'){
		if((r+c)%2 == 0){
			//1
			if(r != n-1 && c != m-1){
				if((state & 2) == 0 && (state & (1 << m)) == 0 && a[r+1][c] == '.' && a[r][c+1] == '.'){
					ans = max(ans, solve(num+2, (state >> 2) | (1 << (m-2))) + 1);
				}
			}
		}
		else{
			//2
			if(r != n-1 && c != m-1){
				if((state & 2) == 0 && a[r+1][c+1] == '.' && a[r][c+1] == '.'){
					ans = max(ans, solve(num+2, (state >> 2) | (1 << (m-1))) + 1);
				}
			}

			//3
			if(r != n-1 && c != m-1){
				if(a[r+1][c+1] == '.' && a[r+1][c] == '.' && (state & (1 << m)) == 0){
					ans = max(ans, solve(num+1, (state >> 1) | (1 << (m) | (1 << (m-1)))) + 1);
				}
			}

			//4
			if(r != n-1 && c > 0){
				if(a[r+1][c-1] == '.' && a[r+1][c] == '.' && (state & (1 << m)) == 0 && (state & (1 << (m-1))) == 0){
					ans = max(ans, solve(num+1, (state >> 1) | (1 << (m-1) | (1 << (m-2)))) + 1);
				}
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

	if(n == 1){
		cout << 0;
	}
	else{
		swap(n, m);
		int cur_state = 0;
		for(int j = 0; j < m; j++){
			if(a[0][j] == 'X'){
				cur_state |= (1 << j);
			} 
		}
		if(a[1][0] == 'X'){
			cur_state |= (1 << m);
		} 

		memset(dp, -1, sizeof(dp));
		cout << solve(0, cur_state);
	}

}
