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
	vector<int> a(m);
	for(int i = 0; i < m; i++){
		cin >> a[i];
	}

	vector<vector<int>> connections(n, vector<int> (n, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> connections[i][j];
		}
	}

	int ans = 0;
	for(int i = 0; i < m-1; i++){
		ans += connections[a[i]-1][a[i+1]-1];
	}
	cout << ans;

}
