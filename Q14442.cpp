#include <bits/stdc++.h>
using namespace std;

int height, width, break_wall;
int graph[1001][1001];
int visited[1001][1001][11];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> height >> width >> break_wall;
    cin.ignore();

    for(int y = 0; y < height; y++){
        string temp;
        getline(cin, temp);
        for(int x = 0; x < width; x++){
            graph[y][x] = temp[x] - '0';
        }
    }
    
    //Keep track of number of walls broken
    struct datas{
        int x;
        int y;
        int walls_broken;
    };

    memset(visited, -1, sizeof(visited));

    queue<datas> q_;
    q_.push({0, 0, 0});
    visited[0][0][0] = 1;

    int dy[4] = {0,0,1,-1};
    int dx[4] = {1,-1,0,0};

    while(!q_.empty()){
        datas temp = q_.front();
        q_.pop();

        for(int i = 0; i < 4; i++){
            int ny = temp.y + dy[i];
            int nx = temp.x + dx[i];
            
            if(ny < 0 || ny >= height || nx < 0 || nx >= width) continue;
            
            //Move onto empty cell
            if(graph[ny][nx] == 0 && visited[ny][nx][temp.walls_broken] == -1){
                visited[ny][nx][temp.walls_broken] = visited[temp.y][temp.x][temp.walls_broken] + 1;
                q_.push({nx, ny, temp.walls_broken});
            }
            //Break wall
            if(temp.walls_broken < break_wall && graph[ny][nx] == 1 && visited[ny][nx][temp.walls_broken + 1] == -1){
                visited[ny][nx][temp.walls_broken + 1] = visited[temp.y][temp.x][temp.walls_broken] + 1;
                q_.push({nx, ny, temp.walls_broken + 1});
            }
        }
    }

    int ans = -1;
    //Check for minimum answer that is not -1(not visited value)
    for(int i = 0; i <= break_wall; i++){
        if(ans == -1 || (ans > visited[height-1][width-1][i] && visited[height-1][width-1][i] != -1)){
            ans = visited[height-1][width-1][i];
        }
    }
    cout << ans;

}


 
