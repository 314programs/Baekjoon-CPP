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

	int n;
	cin >> n;

	vector<string> connection(n);
	vector<vector<int>> visited(n, vector<int>(n, 0));
	const int inf = 1e9;

	for(int i = 0; i < n; i++){
		cin >> connection[i];
		for(int j = 0; j < n; j++){
			if(connection[i][j] == 'Y') visited[i][j] = 1;
			else visited[i][j] = inf;
		}
	}


	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j || j == k || k == i) continue;
				if(visited[i][j] > visited[i][k] + visited[k][j] && visited[i][k] != inf && visited[k][j] != inf){
					visited[i][j] = visited[i][k] + visited[k][j];
				}
			}
		}
	}

	int mx = -1;
	for(int i = 0; i < n; i++){
		int cnt = 0;
		for(int j = 0; j < n; j++){
			if(i != j && visited[i][j] <= 2) cnt++;
		}
		mx = max(cnt, mx);
	}
	cout << mx;

}
