#include <bits/stdc++.h>
using namespace std;

struct node{
    int x, y;
};

int graph[500][500];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int height, width;

int bfs(node start){
    queue<node> q;
    q.push({start});
    int size = 1;
    graph[start.y][start.x] = 2;
    
    while(!q.empty()){
        node current = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if(nx >= 0 && nx < width && ny >= 0 && ny < height && graph[ny][nx] == 1){
                graph[ny][nx] = 2;
                q.push({nx, ny});
                size++;
            }
        }
    }
    return size;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    cin >> height >> width;

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            cin >> graph[y][x];
        }
    }

    int max_area = 0;
    int d_cnt = 0;

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(graph[y][x] == 1){
                max_area = max(bfs({x, y}), max_area);
                d_cnt++;
            }
        }
    }
    cout << d_cnt << "\n" << max_area;
}
