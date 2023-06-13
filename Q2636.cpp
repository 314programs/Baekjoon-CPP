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

int a[105][105];
int new_a[105][105];
bool visited[105][105];

int height, width;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int bfs(){
	queue<pair<int, int>> q;
	q.push({0, 0});
	int cnt = 0;

	while(!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();

		if(visited[cur.first][cur.second]) continue;
		visited[cur.first][cur.second] = true;

		for(int i = 0; i < 4; i++){
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];
			if(ny >= 0 && ny <= height+1 && nx >= 0 && nx <= width+1 && !visited[ny][nx]){
				if(a[ny][nx] == 1){
					new_a[ny][nx] = 0;
					cnt++;
					visited[ny][nx] = true;
				}
				else{
					q.push({ny, nx});
				}
			}
		}
	}

	return cnt;

}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	cin >> height >> width;
	int prev = 0;

	for(int i = 1; i <= height; i++){
		for(int j = 1; j <= width; j++){
			cin >> a[i][j];
			new_a[i][j] = a[i][j];
			if(a[i][j] == 1) prev++;
		}
	}

	int cnt = 0;
	while(true){
		memset(visited, false, sizeof(visited));
		int cur = bfs();
		if(cur == 0) break;

		for(int i = 1; i <= height; i++){
			for(int j = 1; j <= width; j++){
				a[i][j] = new_a[i][j];
			}
		}

		prev = cur;
		cnt++;
	}

	cout << cnt << "\n" << prev;

}
