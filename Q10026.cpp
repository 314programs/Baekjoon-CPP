#include <bits/stdc++.h>
using namespace std;

int dimension;
char graph[100][100];
int visited[100][100];

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

struct datas{
    int x;
    int y;
};

void BFS_queue(int x, int y){
    queue<datas> q_;
    q_.push({x, y});
    visited[y][x] = 1;

    while(!q_.empty()){
        datas temp = q_.front();
        q_.pop();

        for(int i = 0; i < 4; i++){
            int ny = temp.y + dy[i];
            int nx = temp.x + dx[i];

            if(ny < 0 || ny >= dimension || nx < 0 || nx >= dimension || visited[ny][nx] != -1 || graph[temp.y][temp.x] != graph[ny][nx]) continue;
            visited[ny][nx] = 1;
            q_.push({nx, ny});
        }
    }
}

int BFS_loop(void){
    memset(visited, -1, sizeof(visited));
    int ans = 0;

    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            if(visited[y][x] == -1){
                BFS_queue(x, y);
                ans += 1;
            }
        }
    }
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> dimension;
    cin.ignore();

    for(int y = 0; y < dimension; y++){
        string temp;
        getline(cin, temp);
        for(int x = 0; x < dimension; x++){
            graph[y][x] = temp[x];
        }
    }

    cout << BFS_loop() << " ";

    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            if(graph[y][x] == 'R'){
                graph[y][x] = 'G';
            }
        }
    }
    cout << BFS_loop();


}
