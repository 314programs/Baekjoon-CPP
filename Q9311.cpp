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

int visited[16][16];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

	int tc;
	cin >> tc;

	while(tc--){
		int h, w;
		cin >> h >> w;
		vector<string> a(h);
		for(int i = 0; i < h; i++){
			cin >> a[i];
		}

		int st_y, st_x;
		for(int y = 0; y < h; y++){
			for(int x = 0; x < h; x++){
				visited[y][x] = -1;
				if(a[y][x] == 'S'){
					st_y = y;
					st_x = x;
					visited[y][x] = 0;
				}
			}
		}

		int ans = -1;
		queue<pair<int, int>> q;
		q.push(make_pair(st_x, st_y));

		while(!q.empty() && ans == -1){
			pair<int, int> cur = q.front();
			q.pop();

			for(int i = 0; i < 4; i++){
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if(a[ny][nx] != 'X' && visited[ny][nx] == -1){
					if(a[ny][nx] == 'G'){
						ans = visited[cur.second][cur.first] + 1;
						break;
					}
					visited[ny][nx] = visited[cur.second][cur.first] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}

		if(ans != -1){
			cout << "Shortest Path: " << ans << "\n";
		}
		else{
			cout << "No Exit\n";
		}
	}

}
