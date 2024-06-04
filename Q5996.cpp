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

struct node{
	int to, cost;
};

int dist[2600];
bool visited[2600];
int inf = 1e9;

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

	int node_cnt, road_cnt;
	cin >> node_cnt >> road_cnt;
	vector<node> connections[node_cnt+1];

	int s, e;
	cin >> s >> e;

	for(int i = 0; i < road_cnt; i++){
		int a, b, c;
		cin >> a >> b >> c;
		connections[a].push_back({b, c});
		connections[b].push_back({a, c});
	}

	for(int i = 1; i <= node_cnt; i++){
		dist[i] = inf;
	}
	dist[s] = 0;
	memset(visited, false, sizeof(visited));

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, s));

	while(!pq.empty()){
		auto cur = pq.top();
		pq.pop();

		if(visited[cur.second]){
			continue;
		}
		visited[cur.second] = true;

		for(auto ch: connections[cur.second]){
			if(dist[ch.to] > ch.cost + dist[cur.second]){
				dist[ch.to] = ch.cost + dist[cur.second];
				pq.push(make_pair(dist[ch.to], ch.to));
			}
		}
	}

	cout << dist[e];

}
