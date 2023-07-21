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

vector<pair<int, int>> edge[505];
vector<pair<int, int>> rev[505];
int dist[505];
int visited[505];
bool use_edge[505][505];

int n, m;
int s, e;
const int inf = 1e9;

void reset_dist(){
	for(int i = 0; i < n; i++){
		dist[i] = inf;
	}
}

void track(int cur_node, int cur_dist){
	for(auto ch: rev[cur_node]){
		if(cur_dist - ch.second == dist[ch.first]){
			if(!use_edge[ch.first][cur_node]) continue;
			use_edge[ch.first][cur_node] = false;
			track(ch.first, dist[ch.first]);
		}
	}
}

int dijkstra_backtrack(){
	reset_dist();
	memset(visited, false, sizeof(visited));

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});
	dist[s] = 0;

	while(!pq.empty()){
		auto cur = pq.top();
		pq.pop();

		if(visited[cur.second]) continue;
		visited[cur.second] = true;

		for(auto to: edge[cur.second]){
			if(cur.first + to.second < dist[to.first]){
				dist[to.first] = cur.first + to.second;
				pq.push({dist[to.first], to.first});
			}
		}
	}

	if(dist[e] == inf) return -1;
	track(e, dist[e]);
	return dist[e];

}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);
	
	while(true){
		memset(use_edge, false, sizeof(use_edge));
		cin >> n >> m;
		if(n == 0) break;
		cin >> s >> e;

		for(int i = 0; i < n; i++){
			edge[i].clear();
			rev[i].clear();
		}

		for(int i = 0; i < m; i++){
			int a, b, c;
			cin >> a >> b >> c;
			use_edge[a][b] = true;
			edge[a].push_back({b, c});
			rev[b].push_back({a, c});
		}

		int cur = dijkstra_backtrack();
		if(cur != -1){
			memset(visited, false, sizeof(visited));
			reset_dist();

			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
			pq.push({0, s});
			dist[s] = 0;

			while(!pq.empty()){
				auto cur = pq.top();
				pq.pop();

				if(visited[cur.second]) continue;
				visited[cur.second] = true;

				for(auto to: edge[cur.second]){
					if(cur.first + to.second < dist[to.first] && use_edge[cur.second][to.first]){
						dist[to.first] = cur.first + to.second;
						pq.push({dist[to.first], to.first});
					}
				}
			}

			if(dist[e] == inf) dist[e] = -1;
			cout << dist[e] << "\n";

		}
		else{
			cout << -1 << "\n";
		}

	}


}
