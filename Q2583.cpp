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

int a[100][100];
bool visited[100][100];
int height, width, k;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct point{
	int x, y;
};

int bfs(int x, int y){
	queue<point> q;
	visited[y][x] = true;
	q.push({x, y});
	int area = 1;

	while(!q.empty()){
		auto cur = q.front();
		q.pop();

		for(int i = 0; i < 4; i++){
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if(ny >= 0 && ny < height && nx >= 0 && nx < width && a[ny][nx] == 0 && !visited[ny][nx]){
				visited[ny][nx] = true;
				area++;
				q.push({nx, ny});
			}
		}
	}
	return area;

}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	setIO("");

	cin >> height >> width >> k;
	memset(a, 0, sizeof(0));
	memset(visited, false, sizeof(visited));

	for(int i = 0; i < k; i++){
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;

		for(int y = (height-ry); y < (height-ly); y++){
			for(int x = lx; x < rx; x++){
				a[y][x] = 1;
			}
		}
	}

	vector<int> area;
	int cnt = 0;

	for(int y = 0; y < height; y++){
		for(int x = 0; x < width; x++){
			if(a[y][x] == 0 && !visited[y][x]){
				cnt++;
				area.push_back(bfs(x, y));
			}
		}
	}

	sort(area.begin(), area.end());
	cout << cnt << "\n";
	for(auto ch: area){
		cout << ch << ' ';
	}

}
