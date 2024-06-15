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

int visited[1005][1005];

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    int coord_x, coord_y;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 2){
                coord_y = i;
                coord_x = j;
            }
        }
    }

    memset(visited, -1, sizeof(visited));
    visited[coord_y][coord_x] = 0;
    queue<pair<pair<int, int>, int>> q;
    q.push({{coord_x, coord_y}, 0});

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    while(!q.empty()){
        auto cur = q.front().first;
        int cur_cost = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && visited[ny][nx] == -1 && a[ny][nx] != 0){
                visited[ny][nx] = cur_cost + 1;
                q.push({{nx, ny}, cur_cost+1});
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 0) visited[i][j] = 0;
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }




}
