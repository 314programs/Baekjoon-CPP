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

bool visited[100005];

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> coords(n);
	for(int i = 0; i < n; i++){
		cin >> coords[i].first >> coords[i].second;
	}

	vector<vector<int>> connection(n);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		connection[a].push_back(b);
		connection[b].push_back(a);
	}

	int ans = 1e11;
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			visited[i] = true;
			queue<int> q;
			q.push(i);

			int min_x = 1e9; int min_y = 1e9;
			int max_x = -1e9; int max_y = -1e9;
			while(!q.empty()){
				int cur = q.front();
				q.pop();

				min_x = min(coords[cur].first, min_x);
				max_x = max(coords[cur].first, max_x);
				min_y = min(coords[cur].second, min_y);
				max_y = max(coords[cur].second, max_y);

				for(auto ch: connection[cur]){
					if(!visited[ch]){
						visited[ch] = true;
						q.push(ch);
					}
				}
			}
			ans = min(ans, 2*((max_x-min_x) + (max_y-min_y)));
		}
	}
	cout << ans;

}
