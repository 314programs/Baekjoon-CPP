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
	const int inf = 10000;

	int dx[4] = {0,0,1,-1};
	int dy[4] = {1,-1,0,0};

	vector<string> a(n);
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	int dist[50][50];
	memset(dist, inf, sizeof(dist));

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({0, {0, 0}});
	dist[0][0] = 0;

	while(!pq.empty()){
		auto cur = pq.top();
		int cost = -cur.first;
		pair<int, int> pos = cur.second;
		pq.pop();

		if(visited[pos.first][pos.second]) continue;
		visited[pos.first][pos.second] = true;

		for(int i = 0; i < 4; i++){
			int ny = dy[i] + pos.first;
			int nx = dx[i] + pos.second;
			int new_cost = 0;
			if(ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx]){
				if(a[ny][nx] == '0') new_cost++;
				if(dist[ny][nx] > new_cost + cost){
					dist[ny][nx] = new_cost + cost;
					pq.push({-dist[ny][nx], {ny, nx}});
				}
			}
		}
	}
	cout << dist[n-1][n-1];

}
