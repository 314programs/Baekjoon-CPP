#include <bits/stdc++.h>
using namespace std;

int graph[500][500];
int dy[8] = {1,-1,0,0,1,1,-1,-1};
int dx[8] = {0,0,1,-1,1,-1,1,-1};
int ans[500][500];
int height, width;

struct coord{
    int x, y;
};

//Visited stores coordinates where ball ends up
coord visited[500][500];

coord dfs(coord start){
    int min_val = graph[start.y][start.x];
    int min_i = -1;
    
    //Look for minimum value that is lower then current one
    for(int i = 0; i < 8; i++){
        int ny = start.y + dy[i];
        int nx = start.x + dx[i];
        if(ny >= 0 && ny < height && nx >= 0 && nx < width){
            if(min_val == -1 || graph[ny][nx] < min_val){
                min_val = graph[ny][nx];
                min_i = i;
            }
        }
    }
    
    //If no min value found return
    if(min_i == -1){
        visited[start.y][start.x] = start;
        return start;
    }
    
    //If value already exists
    if(visited[start.y + dy[min_i]][start.x + dx[min_i]].x != -1){
        visited[start.y][start.x] = visited[start.y + dy[min_i]][start.x + dx[min_i]];
        return visited[start.y][start.x];
    }
    
    //Else move to the minimum spot
    else{
        visited[start.y][start.x] = dfs({start.x + dx[min_i], start.y + dy[min_i]});
        return visited[start.y][start.x];
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> height >> width;
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            visited[y][x] = {-1, -1};
            cin >> graph[y][x];
        }
    }
  
    memset(ans, 0, sizeof(ans));
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(visited[y][x].x == -1){
                dfs({x, y});
            }
            ans[visited[y][x].y][visited[y][x].x]++;
        }
    }


    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            cout << ans[y][x] << " ";
        }
        cout << "\n";
    }

}
