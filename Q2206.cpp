#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int height, width;
    cin >> height >> width;
    int graph[height][width];
    
    //Set up visited
    int visited[height][width][2];
    memset(visited, -1, sizeof(visited));
    cin.ignore();
    
    //Get input
    for(int y = 0; y < height; y++){
        string temp;
        getline(cin, temp);
        for(int x = 0; x < width; x++){
            graph[y][x] = temp[x] - '0';
        }
    }
    
    //Struct for easier code management
    struct datas{
        int x;
        int y;
        int wall_broken;
    };

    queue<datas> q_;
    q_.push({0,0,0});
    visited[0][0][0] = 1;

    int dy[4] = {0,0,1,-1};
    int dx[4] = {1,-1,0,0};

    while(!q_.empty()){
        datas temp = q_.front();
        q_.pop();

        for(int i = 0; i < 4; i++){
            int nx = dx[i] + temp.x;
            int ny = dy[i] + temp.y;
            
            //Continue if out of bounds
            if(nx < 0 || nx >= width || ny < 0 || ny >= height) continue;
            
            //If moving to an empty space
            if(graph[ny][nx] == 0 && visited[ny][nx][temp.wall_broken] == -1){
                visited[ny][nx][temp.wall_broken] = visited[temp.y][temp.x][temp.wall_broken] + 1;
                q_.push({nx, ny, temp.wall_broken});
            }
          
            //If moving to a wall
            else if(temp.wall_broken == 0 && graph[ny][nx] == 1 && visited[ny][nx][1] == -1){
                visited[ny][nx][1] = visited[temp.y][temp.x][temp.wall_broken] + 1;
                q_.push({nx, ny, 1});
            }
        }
    }
    
    //Check for the shortest route that is not -1
    if(visited[height-1][width-1][0] != -1 && visited[height-1][width-1][1] != -1){
        cout << min(visited[height-1][width-1][0], visited[height-1][width-1][1]);
    }
    else{
        cout << max(visited[height-1][width-1][0], visited[height-1][width-1][1]);
    }


}


 
