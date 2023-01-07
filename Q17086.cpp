#include <bits/stdc++.h>
using namespace std;

int height, width;
int graph[50][50];
int visited[50][50];

int dy[8] = {0,0,1,-1,1,1,-1,-1};
int dx[8] = {1,-1,0,0,1,-1,1,-1};

struct point{
    int x,y;
};

//Each safe distance is calculated
int bfs(int x, int y){
    int t_ans = 2500;
    queue<point> q;
    q.push({x,y});
    memset(visited, -1, sizeof(visited));
    visited[y][x] = 0;

    while(!q.empty()){
        point temp = q.front();
        q.pop();

        for(int i = 0; i < 8; i++){
            int ny = dy[i] + temp.y;
            int nx = dx[i] + temp.x;
            if(ny >= 0 && ny < height && nx >= 0 && nx < width && visited[ny][nx] == -1){
                visited[ny][nx] = visited[temp.y][temp.x]+1;
                if(graph[ny][nx] == 1) t_ans = min(t_ans, visited[ny][nx]);
                q.push({nx, ny});
            }
        }
    }
    return t_ans;

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int ans = 0;
    cin >> height >> width;
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            cin >> graph[y][x];
        }
    }

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(graph[y][x] == 0){
                ans = max(bfs(x, y), ans);
            }
        }
    }

    cout << ans;

}
