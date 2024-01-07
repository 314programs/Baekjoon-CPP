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

struct point{
	int x, y, dist;
};

int height, width;
string a[55];
int visited[55][55];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int bfs(int s_y, int s_x){
	queue<point> q;
	q.push({s_x, s_y, 0});
	int ans = 0;

	while(!q.empty()){
		auto cur = q.front();
		q.pop();

		if(visited[cur.y][cur.x] != -1) continue;
		visited[cur.y][cur.x] = cur.dist;
		ans = max(ans, cur.dist);

		for(int i = 0; i < 4; i++){
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if(ny >= 0 && ny < height && nx >= 0 && nx < width && a[ny][nx] == 'L'){
				q.push({nx, ny, cur.dist+1});
			}
		}
	}
	
	return ans;

}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	cin >> height >> width;
	for(int i = 0; i < height; i++){
		cin >> a[i];
	}

	int ans = 0;
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			if(a[i][j] == 'L'){
				memset(visited, -1, sizeof(visited));
				ans = max(ans, bfs(i, j));
			}
		}
	}

	cout << ans;
	
}
