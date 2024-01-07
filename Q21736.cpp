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

int visited[605][605];

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    int start_x, start_y;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'I'){
                start_x = j;
                start_y = i;
            }
        }
    }

    memset(visited, false, sizeof(visited));
    visited[start_y][start_x] = true;
    queue<pair<int, int>> q;
    q.push({start_x, start_y});

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int ans = 0;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[ny][nx] && a[ny][nx] != 'X'){
                if(a[ny][nx] == 'P') ans++;
                q.push({nx, ny});
                visited[ny][nx] = true;
            }
        }
    }

    if(ans == 0){
        cout << "TT";
    }
    else{
        cout << ans;
    }

}
