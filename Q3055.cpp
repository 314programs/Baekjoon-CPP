#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int height, width;
    cin >> height >> width;
    cin.ignore();

    char graph[height][width];
    int visited[height][width];
    memset(visited, -1, sizeof(visited));

    struct datas{
        int x;
        int y;
        bool water;
    };

    queue<datas> q_;
    int final_x, final_y;

    for(int y = 0; y < height; y++){
        string temp;
        getline(cin, temp);
        for(int x = 0; x < width; x++){
            graph[y][x] = temp[x];
            if(graph[y][x] == 'S'){
                visited[y][x] = 0;
                q_.push({x, y, false});
            }
        }
    }


    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(graph[y][x] == 'D'){
                final_x = x;
                final_y = y;
            }
            //Water == -2
            else if(graph[y][x] == '*'){
                q_.push({x,y,true});
                visited[y][x] = -2;
            }
            //Wall == -3
            else if(graph[y][x] == 'X'){
                visited[y][x] = -3;
            }
        }
    }

    int dy[4] = {1,-1,0,0};
    int dx[4] = {0,0,1,-1};

    string ans = "KAKTUS";

    while(!q_.empty()){
        datas temp = q_.front();
        q_.pop();

        if(ans != "KAKTUS") break;
        if(temp.water == false && visited[temp.y][temp.x] == -2) continue;

        for(int i = 0; i < 4; i++){
            int ny = temp.y + dy[i];
            int nx = temp.x + dx[i];

            if(ny < 0 || ny >= height || nx < 0 || nx >= width) continue;

            if(temp.water == true){
                if(visited[ny][nx] >= -1 && graph[ny][nx] == '.'){
                    visited[ny][nx] = -2;
                    q_.push({nx, ny, temp.water});
                }
            }

            else{
                if(visited[ny][nx] == -1 && (graph[ny][nx] == '.' || graph[ny][nx] == 'D')){
                    visited[ny][nx] = visited[temp.y][temp.x] + 1;
                    if(graph[ny][nx] == 'D'){
                        ans = "FOUND";
                        cout << visited[ny][nx];
                        break;
                    }
                    q_.push({nx, ny, temp.water});
                }
            }    
        }
    }

    if(ans == "KAKTUS") cout << ans;

}


 
