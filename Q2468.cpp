#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int n;
int a[100][100];
bool visited[100][100];

struct point{
    int x, y;
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(point start, int sink){
    queue<point> q;
    q.push(start);
    visited[start.y][start.x] = 1;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx] && a[ny][nx] > sink){
                visited[ny][nx] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for(int k = 0; k <= 100; k++){
        int cnt = 0;
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] > k && !visited[i][j]){
                    bfs({j, i}, k);
                    cnt++;
                }
            }
        }

        ans = max(ans, cnt);
    }
    cout << ans;

}
