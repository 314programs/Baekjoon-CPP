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

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	int DP[1005];
	DP[0] = 0;
	DP[1] = 1;

	int n;
	cin >> n;
	for(int i = 2; i <= n; i++){
		DP[i] = 0;
		if(i-1 >= 0 && DP[i-1] == 0){
			DP[i] = 1;
		}
		if(i-3 >= 0 && DP[i-3] == 0){
			DP[i] = 1;
		}
		if(i-4 >= 0 && DP[i-4] == 0){
			DP[i] = 1;
		}
	}

	if(DP[n] == 1) cout << "SK";
	else cout << "CY";
	
}
