//Had to do this question again because rejudge...
//They said there was no 0 in test case, turns out there is!

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

	int n, m;
	cin >> n >> m;
	vector<int> memory(n);
	vector<int> cost(n);

	for(int i = 0; i < n; i++){
		cin >> memory[i];
	}

	int total_cost = 0;
	for(int i = 0; i < n; i++){
		cin >> cost[i];
		total_cost += cost[i];
	}

	vector<int> DP(total_cost+1, 0);
	for(int i = 0; i < n; i++){
		for(int j = total_cost; j >= cost[i]; j--){
			DP[j] = max(memory[i] + DP[j-cost[i]], DP[j]);
		}
	}

	for(int i = 0; i <= total_cost; i++){
		if(DP[i] >= m){
			cout << i;
			break;
		}
	}
	
}
