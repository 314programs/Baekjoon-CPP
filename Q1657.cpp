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

int value[5][5] = {
	{10, 8, 7, 5, 1},
	{8, 6, 4, 3, 1},
	{7, 4, 3, 2, 1},
	{5, 3, 2, 2, 1},
	{1, 1, 1, 1, 0}
};

//Index, state
int dp[300][1 << 14];
int h, w;
int a[16][16];

int solve(int idx, int state){
	if(idx == h*w){
		return 0;
	}
	if(idx >= h*w){
		return -10000000;
	}
	if(dp[idx][state] != -1){
		return dp[idx][state];
	}

	int &ans = dp[idx][state];
	ans = 0;
	int r = idx/w;
	int c = idx%w;

	//Three options, no placement, vertical placement, horizontal placement

	//No placement
	ans = max(ans, solve(idx+1, state >> 1));

	int points = 0;

	if(!(state & 1)){
		int new_state = state;
		new_state = new_state >> 1;

		//Horizontal placement
		if(!(new_state & 1) && c != w-1){
			points = value[a[r][c]][a[r][c+1]];
			ans = max(ans, solve(idx+1, (new_state | 1)) + points);
		}

		//Vertical placement
		if(!(new_state & (1 << (w-1))) && r != h-1){
			points = value[a[r][c]][a[r+1][c]];
			ans = max(ans, solve(idx+1, (new_state | (1 << (w-1)))) + points);
		}
	}

	return ans;

}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	memset(dp, -1, sizeof(dp));
	cin >> h >> w;

	for(int i = 0; i < h; i++){
		string s;
		cin >> s;
		for(int j = 0; j < w; j++){
			if(s[j] != 'F'){
				a[i][j] = s[j] - 'A';
			}
			else{
				a[i][j] = 4;
			}
		}
	}

	for(int i = 0; i < w; i++){
		a[h][i] = 4;
	}

	cout << solve(0, 0);

}
