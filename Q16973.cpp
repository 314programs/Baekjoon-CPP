#include <bits/stdc++.h>
using namespace std;

int graph[1001][1001];
int visited[1001][1001];
int height, width;
int sq_h, sq_w;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

struct coord{
    int x, y;
};


bool check(int ix, int iy){
    //Checking for walls or out of bounds using the sides of the square
    for(int y = iy; y < iy + sq_h; y++){
        int x = ix;
        if(graph[y][x] == 1 || y < 1 || y > height || x < 1 || x > width) return false;
        
        x = ix + sq_w - 1;
        if(graph[y][x] == 1 || y < 1 || y > height || x < 1 || x > width) return false;
    }

    for(int x = ix; x < ix + sq_w; x++){
        int y = iy;
        if(graph[y][x] == 1 || y < 1 || y > height || x < 1 || x > width) return false;

        y = iy + sq_h - 1;
        if(graph[y][x] == 1 || y < 1 || y > height || x < 1 || x > width) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> height >> width;
    for(int y = 1; y <= height; y++){
        for(int x = 1; x <= width; x++){
            cin >> graph[y][x];
        }
    }

    int start_x, start_y, end_x, end_y;
    cin >> sq_h >> sq_w >> start_y >> start_x >> end_y >> end_x;

    queue<coord> q;
    q.push({start_x, start_y});
    memset(visited, -1, sizeof(visited));
    visited[start_y][start_x] = 0;
    
    //Using left top as the point to move around
    //Basic BFS
    while(!q.empty()){
        coord current = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if(visited[ny][nx] == -1 && check(nx, ny)){
                visited[ny][nx] = visited[current.y][current.x]+1;
                q.push({nx, ny});
            }
        }
    }

    cout << visited[end_y][end_x];

}
