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

	int cnt = 1;
	const int inf = 1e17;
	int visited[130][130];

	int dx[4] = {0,0,1,-1};
	int dy[4] = {1,-1,0,0};

	while(true){
		int n;
		cin >> n;

		if(n == 0) break;
		vector<vector<int>> a(n, vector<int>(n));
		vector<vector<int>> dist(n, vector<int>(n, inf));
		memset(visited, 0, sizeof(visited));

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}

		priority_queue<pair<int, pair<int, int>>> pq;
		pq.push({-a[0][0], {0, 0}});
		dist[0][0] = a[0][0];

		while(!pq.empty()){
			auto cur = pq.top();
			pair<int, int> pos = cur.second;
			int cost = -cur.first;
			pq.pop();

			if(visited[pos.first][pos.second]) continue;
			visited[pos.first][pos.second] = 1;

			for(int i = 0; i < 4; i++){
				int ny = pos.first + dy[i];
				int nx = pos.second + dx[i];
				if(ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx]){
					if(dist[ny][nx] > cost + a[ny][nx]){
						dist[ny][nx] = cost + a[ny][nx];
						pq.push({-dist[ny][nx], {ny, nx}});
					}
				}
			}
		}

		cout << "Problem " << cnt << ": " << dist[n-1][n-1] << "\n";
		cnt++;
	}

}
