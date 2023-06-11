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
	vector<int> connection[n+1];

	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		connection[b].push_back(a);
	}

	vector<pair<int, int>> ans(n+1, {0, 0});
	int visited[n+1];

	for(int i = 1; i <= n; i++){
		queue<int> q;
		q.push(i);
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		int cnt = 1;

		while(!q.empty()){
			int cur = q.front();
			q.pop();

			for(auto ch: connection[cur]){
				if(visited[ch]) continue;
				visited[ch] = 1;
				cnt++;
				q.push(ch);
			}
		}
		ans[i] = {cnt, i};
	}

	sort(ans.begin(), ans.end(), [&](auto &u, auto &v){
		if(u.first == v.first){
			return u.second < v.second;
		}
		return u.first > v.first;
	});
	int mx = ans[0].first;

	for(int i = 0; i < n; i++){
		if(ans[i].first == mx){
			cout << ans[i].second << " ";
		}
	}
	
}
