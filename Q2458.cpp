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
	const int inf = 1e9;
	vector<vector<int>> visited(n+1, vector<int>(n+1, inf));

	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		visited[a][b] = 1;
	}

	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j || i == k || j == k) continue;
				if(visited[i][j] > visited[i][k] + visited[k][j] && visited[i][k] != inf && visited[k][j] != inf){
					visited[i][j] = visited[i][k] + visited[k][j];
				}
			}
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		for(int j = 1; j <= n; j++){
      //Knows smaller or taller
			if(visited[i][j] < inf || visited[j][i] < inf) cnt++;
		}
		if(cnt == n-1) ans++;
	}
	cout << ans;

}
