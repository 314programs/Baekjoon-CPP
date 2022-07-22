#include <bits/stdc++.h>
using namespace std;

int height, width;
char graph[500][500];

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

struct point{
    int x, y;
};

bool BFS(int x, int y){
    int visited[height][width];
    memset(visited, 0, sizeof(visited));

    deque<point> dq;
    dq.push_back({x, y});
    visited[y][x] = 1;

    while(!dq.empty()){
        point temp = dq.front();
        dq.pop_front();

        for(int i = 0; i < 4; i++){
            int ny = temp.y + dy[i];
            int nx = temp.x + dx[i];
            if(ny >= 0 && ny < height && nx >= 0 && nx < width && graph[ny][nx] != 'D' && visited[ny][nx] == 0){
                if(graph[ny][nx] == 'S') return true;
                dq.push_back({nx, ny});
                visited[ny][nx] = 1;
            }
        }
    }
    return false;

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
      
    cin >> height >> width;
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            cin >> graph[y][x];
            //Filled the field with fence
            if(graph[y][x] == '.') graph[y][x] = 'D';
        }
    }

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(graph[y][x] == 'W'){
                bool temp = BFS(x, y);
                if(temp == true){
                    cout << 0;
                    return 0;
                }
            }
        }  
    }

    cout << 1 << "\n";
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            cout << graph[y][x];
        }
        cout << "\n";
    }


}
