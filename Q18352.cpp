//I need to work on my game for couple of days..
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

vector<int> edge[300005];
bool visited[300005];

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	int n, m, k, start;
	cin >> n >> m >> k >> start;

	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
	}

	queue<pair<int, int>> q;
	q.push({start, 0});
	vector<int> ans;

	while(!q.empty()){
		int cur_node = q.front().first;
		int cur_dist = q.front().second;
		q.pop();

		if(visited[cur_node]){
			continue;
		}
		visited[cur_node] = true;
		if(cur_dist == k){
			ans.push_back(cur_node);
		}

		for(auto ch: edge[cur_node]){
			if(!visited[ch]){
				q.push({ch, cur_dist+1});
			}
		}
	}
	sort(ans.begin(), ans.end());
	
	if(ans.size() == 0){
		cout << -1;
	}
	else{
		for(auto ch: ans){
			cout << ch << "\n";
		}
	}


}
