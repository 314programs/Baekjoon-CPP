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

vector<pair<int, int>> connection[50001];
bool visited[50001];
int dist[50001];

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		connection[a].push_back({c, b});
		connection[b].push_back({c, a});
	}

	int inf = 1e12;
	for(int i = 1; i <= n; i++){
		dist[i] = 1e12;
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 1});

	while(!pq.empty()){
		auto cur = pq.top();
		pq.pop();

		if(visited[cur.second]){
			continue;
		}
		visited[cur.second] = true;

		for(auto ch: connection[cur.second]){
			if(dist[ch.second] > cur.first + ch.first){
				dist[ch.second] = cur.first + ch.first;
				pq.push({dist[ch.second], ch.second});
			}
		}
	}

	cout << dist[n];

    
}
