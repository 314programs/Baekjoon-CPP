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

int n, l, r;
int a[55][55];
int new_a[55][55];
bool visited[55][55];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


int bfs(int x, int y){
	if(visited[y][x]) return 0;
	queue<pair<int, int>> q;
	q.push({y, x});
	bool flag = false;

	vector<pair<int, int>> change;
	int total = 0;
	int cnt = 0;

	while(!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();

		if(visited[cur.first][cur.second]) continue;
		visited[cur.first][cur.second] = true;
		total += a[cur.first][cur.second];
		cnt++;
		change.push_back({cur.first, cur.second});

		for(int i = 0; i < 4; i++){
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];
			if(ny >= 0 && ny < n && nx >= 0 && nx < n){
				int diff = abs(a[cur.first][cur.second]-a[ny][nx]);
				if(diff >= l && diff <= r){
					q.push({ny, nx});
				}
			}
		}
	}

	if(cnt <= 1){
		visited[y][x] = false;
		return 0;
	}

	int change_to = total/cnt;
	for(auto ch: change){
		new_a[ch.first][ch.second] = change_to;
	}
	return 1;

}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	cin >> n >> l >> r;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			new_a[i][j] = a[i][j];
		}
	}

	int ans = 0;
	while(true){
		memset(visited, false, sizeof(visited));
		int cnt = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cnt += bfs(j, i);
			}
		}

		if(cnt == 0) break;
		ans++;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				a[i][j] = new_a[i][j];
			}
		}
	}

	cout << ans;

}
