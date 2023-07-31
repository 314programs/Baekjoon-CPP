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

double DP[1 << 21];
double a[21][21];
int n;

int mission_num(int state){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(state & (1 << i)){
			cnt++;
		}
	}
	return cnt;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	cin >> n;
	memset(DP, -1, sizeof(DP));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] != 0) a[i][j] /= 100;
		}
	}

	for(int state = 0; state < (1 << (n+1)); state++){
		DP[state] = -1;
	}

	DP[0] = 1;
	for(int state = 0; state < (1 << (n+1)); state++){
		if(DP[state] == -1) continue;

		//j = agent, i = mission
		int i = mission_num(state);
		for(int j = 1; j <= n; j++){
			if(state & (1 << j)) continue;
			double new_cost = a[i+1][j] * DP[state];
			DP[state | (1 << j)] = max(new_cost, DP[state | (1 << j)]);
		}
	}

	cout << fixed << setprecision(7) << DP[(1 << (n+1))-2] * 100;


}
