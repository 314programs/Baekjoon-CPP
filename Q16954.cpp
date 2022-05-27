#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    char graph[8][8];
    int visited[8][8][9];
    memset(visited, 0, sizeof(visited));

    for(int y = 0; y < 8; y++){
        string temp;
        getline(cin, temp);
        for(int x = 0; x < 8; x++){
            graph[y][x] = temp[x];
        }
    }

    struct datas{
        int x;
        int y;
        int time;
    };

    queue<datas> q_;
    q_.push({0, 7, -1});
    
    //All directions
    int dy[9] = {1,-1,0,0,1,1,-1,-1,0};
    int dx[9] = {0,0,1,-1,1,-1,1,-1,0};

    while(!q_.empty()){
        datas temp = q_.front();
        q_.pop();

        for(int i = 0; i < 9; i++){
            int ny = temp.y + dy[i];
            int nx = temp.x + dx[i];
            int nt = min(temp.time + 1, 8);
            
            //Outside bounds?
            if(ny < 0 || ny >= 8 || nx < 0 || nx >= 8) continue;
            //If merged with wall?
            if(ny - nt >= 0 && graph[ny-nt][nx] == '#') continue;
            //Collid with wall?
            if(ny - nt - 1 >= 0 && graph[ny-nt-1][nx] == '#') continue;

            if(visited[ny][nx][nt] == 0){
                visited[ny][nx][nt] = 1;
                q_.push({nx, ny, nt});
            }
        }
    }

    cout << visited[0][7][8];

}


 
