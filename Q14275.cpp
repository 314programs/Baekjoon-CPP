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
int pow3[9];
long long mod = 1000000007;
int DP[805][20000];


//0: Even, 1: Odd, 2: Not filled
int solve(int num, int state){
	if(num == n * m){
		while(state > 0){
			if(state % 3 == 1) return 0;
			state /= 3;
		}
		return 1;
	}

	int &ans = DP[num][state];
	if(ans != -1) return ans;
	ans = 0;

	int up = (state/pow3[m-1])%3;
	int left = (state/pow3[0])%3;

	int color_left = 2;
	if(left == 0){
		color_left = 1;
	}
	else if(left == 1){
		color_left = 0;
	}

	int cur = 0;
	if(left != 2){
		cur = 1;
	}
	if(num%m == 0){
		color_left = left;
		cur = 0;
	}

	int new_state = (state - up * pow3[m-1] - left * pow3[0]) * 3;
	//Up empty
	if(up == 2){
		ans += solve(num+1, new_state + left * pow3[1] + 2);
		ans += solve(num+1, new_state + color_left * pow3[1] + cur);
	}
	//Up colored
	else{
		if(up == 0){
			ans += solve(num+1, new_state + left * pow3[1] + 2);
		}
		else{
			ans += solve(num+1, new_state + color_left * pow3[1] + (1-cur));
		}
	}
	ans %= mod;
	return ans;

}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	
	cin >> n >> m;
	int size = (1 << m);

	pow3[0] = 1;
	for(int i = 1; i <= m; i++){
		pow3[i] = pow3[i-1] * 3;
		//pow3[i] %= mod;
	}

	int state = 0;
	for(int i = 0; i < m; i++){
		state = state * 3 + 2;
	}
	memset(DP, -1, sizeof(DP));
	cout << solve(0, state);

}
