#include <bits/stdc++.h>
using namespace std;

//Code very similar to Q14442 but with day attatched to it
int height, width, break_wall;
int graph[1001][1001];
int visited[1001][1001][11][2];

bool toggle(bool temp){
    if(temp == true) return false;
    else return true;
}

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

    struct datas{
        int x;
        int y;
        int walls_broken;
        bool day;
    };

    memset(visited, -1, sizeof(visited));

    queue<datas> q_;
    q_.push({0, 0, 0, true});
    visited[0][0][0][1] = 1;

    int dy[5] = {0,0,1,-1};
    int dx[5] = {1,-1,0,0};

    while(!q_.empty()){
        datas temp = q_.front();
        q_.pop();

        for(int i = 0; i < 4; i++){
            int ny = temp.y + dy[i];
            int nx = temp.x + dx[i];

            if(ny < 0 || ny >= height || nx < 0 || nx >= width) continue;

            if(graph[ny][nx] == 0 && visited[ny][nx][temp.walls_broken][toggle(temp.day)] == -1){
                visited[ny][nx][temp.walls_broken][toggle(temp.day)] = visited[temp.y][temp.x][temp.walls_broken][temp.day] + 1;
                q_.push({nx, ny, temp.walls_broken, toggle(temp.day)});
            }
            if(temp.day == true && temp.walls_broken < break_wall && graph[ny][nx] == 1 && visited[ny][nx][temp.walls_broken + 1][toggle(temp.day)] == -1){
                visited[ny][nx][temp.walls_broken + 1][toggle(temp.day)] = visited[temp.y][temp.x][temp.walls_broken][temp.day] + 1;
                q_.push({nx, ny, temp.walls_broken + 1, toggle(temp.day)});
            }
        }
        //Staying still
        if(visited[temp.y][temp.x][temp.walls_broken][toggle(temp.day)] == -1){
            visited[temp.y][temp.x][temp.walls_broken][toggle(temp.day)] = visited[temp.y][temp.x][temp.walls_broken][temp.day] + 1;
            q_.push({temp.x, temp.y, temp.walls_broken, toggle(temp.day)});
        }
    }
    
    //Locate answer
    int ans = -1;
    for(int i = 0; i <= break_wall; i++){
        for(int j = 0; j < 2; j++){
            if(ans == -1 || (ans > visited[height-1][width-1][i][j] && visited[height-1][width-1][i][j] != -1)){
                ans = visited[height-1][width-1][i][j];
            }
        }
    }
    cout << ans;

}


 
