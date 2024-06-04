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

int inf = 10e9;
int dist[5010];
bool visited[5010];

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<node> connections[n+1];

	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		connections[a].push_back({b, c});
		connections[b].push_back({a, c});
	}

	int s, e;
	cin >> s >> e;

	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= n; i++){
		dist[i] = inf;
	}
	dist[s] = 0;

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
			if(dist[ch.to] > ch.cost + cur.first){
				dist[ch.to] = ch.cost + cur.first;
				pq.push(make_pair(dist[ch.to], ch.to));
			}
		}
	}
	cout << dist[e];

}
