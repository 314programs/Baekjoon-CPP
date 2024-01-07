#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int height, width;
    cin >> width >> height;
    cin.ignore();

    char graph[height][width];
    int visited[height][width];
    memset(visited, -1, sizeof(visited));
    
    //Turning is stored as a variable
    struct datas{
        int x;
        int y;
        int turn;
    };

    int cx_1 = -1, cy_1 = -1, cx_2 = -1, cy_2 = -1;

    for(int y = 0; y < height; y++){
        string temp;
        getline(cin, temp);
        for(int x = 0; x < width; x++){
            graph[y][x] = temp[x];
            if(graph[y][x] == 'C' && cx_1 == -1){
                cx_1 = x;
                cy_1 = y;
            }
            else if(graph[y][x] == 'C' && cx_1 != -1){
                cx_2 = x;
                cy_2 = y;
            }
        }
    }

    queue<datas> q_;
    q_.push({cx_1, cy_1, 0});
    visited[cy_1][cx_1] = 1;

    int dy[4] = {1,-1,0,0};
    int dx[4] = {0,0,1,-1};

    while(!q_.empty()){
        datas temp = q_.front();
        q_.pop();

        for(int i = 0; i < 4; i++){
            int ny = temp.y + dy[i];
            int nx = temp.x + dx[i];
            
            //Keep moving until turn
            while(ny >= 0 && ny < height && nx >= 0 && nx < width){
                if(graph[ny][nx] == '*') break;
                if(visited[ny][nx] == -1){
                    visited[ny][nx] = temp.turn;
                    q_.push({nx, ny, temp.turn+1});
                }
                ny += dy[i];
                nx += dx[i];
            }
        }
    }

    cout << visited[cy_2][cx_2];

}


 
