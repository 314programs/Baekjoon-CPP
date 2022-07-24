#include <bits/stdc++.h>
using namespace std;

struct movement{
    int x, y, horse;
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int max_horse;
    cin >> max_horse;

    int width, height;
    cin >> width >> height;

    int graph[200][200];
    //y, x, current_horsemove
    int visited[200][200][31];
    memset(visited, -1, sizeof(visited));

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            cin >> graph[y][x];
        }
    }

    deque<movement> dq;
    dq.push_back({0, 0, 0});
    visited[0][0][0] = 0;

    int dx[12] = {0,0,1,-1,1,2,2,1,-1,-2,-2,-1};
    int dy[12] = {1,-1,0,0,2,1,-1,-2,-2,-1,1,2};
    while(!dq.empty()){
        movement temp = dq.front();
        dq.pop_front();
        
        for(int i = 0; i < 12; i++){
            int ny = temp.y + dy[i];
            int nx = temp.x + dx[i];
            //Separate horse movement and monkey movement
            //Store least amount of movements
            if(nx >= 0 && nx < width && ny >= 0 && ny < height && graph[ny][nx] == 0){
                if(i < 4 && (visited[ny][nx][temp.horse] == -1 || visited[ny][nx][temp.horse] > visited[temp.y][temp.x][temp.horse] + 1)){
                    visited[ny][nx][temp.horse] = visited[temp.y][temp.x][temp.horse] + 1;
                    dq.push_back({nx, ny, temp.horse});
                }
                else if(i >= 4 && temp.horse+1 <= max_horse && (visited[ny][nx][temp.horse+1] == -1 || visited[ny][nx][temp.horse+1] > visited[temp.y][temp.x][temp.horse] + 1)){
                    visited[ny][nx][temp.horse+1] = visited[temp.y][temp.x][temp.horse] + 1;
                    dq.push_front({nx, ny, temp.horse+1});
                }
            }
        }
    }

    int ans = -1;
    for(int i = 0; i < 31; i++){
        if(ans == -1 || (ans > visited[height-1][width-1][i] && visited[height-1][width-1][i] != -1)){
            ans = visited[height-1][width-1][i];
        }
    }

    cout << ans;

}
