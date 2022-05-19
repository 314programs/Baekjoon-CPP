#include <bits/stdc++.h>
using namespace std;

int height, width;
int graph[8][8];
int visited[8][8];

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

void coordinate(int num, int val){
    graph[num/width][num%width] = val;
}

int bfs(void){
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q_;
    
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(graph[y][x] == 1){
                visited[y][x] = 1;
            }
            if(graph[y][x] == 2){
                visited[y][x] = 2;
                q_.push(make_pair(y, x));
            }
        }
    }

    while(!q_.empty()){
        int temp_x = q_.front().second;
        int temp_y = q_.front().first;
        q_.pop();

        for(int i = 0; i < 4; i++){
            int ny = temp_y + dy[i];
            int nx = temp_x + dx[i];
            if(ny >= 0 && ny < height && nx >= 0 && nx < width && visited[ny][nx] == 0){
                q_.push(make_pair(ny, nx));
                visited[ny][nx] = 2;
            }
        }
    }

    int safe = 0;
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(visited[y][x] == 0){
                safe += 1;
            }
        }
    }
    return safe;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> height >> width;
    int ans = 0;

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            cin >> graph[y][x];
        }
    }

    int area = height*width;
    //Tried simplifying code but got confused with x/width, x%height...
    for(int x = 0; x < area; x++){
        for(int y = x+1; y < area; y++){
            for(int z = y+1; z < area; z++){
                if(graph[x/width][x%width] != 0 || graph[y/width][y%width] != 0 || graph[z/width][z%width] != 0) continue;
                coordinate(x, 1); coordinate(y, 1); coordinate(z, 1);
                ans = max(bfs(), ans);
                coordinate(x, 0); coordinate(y, 0); coordinate(z, 0);
            }
        }
    }
    cout << ans;

}


 
