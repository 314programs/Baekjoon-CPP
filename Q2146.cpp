#include <bits/stdc++.h>
using namespace std;

int graph[100][100];
int visited[100][100];
int dimension;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

void BFS_locate(int y_, int x_, int flag){
    queue<pair<int, int>> q_;
    q_.push(make_pair(y_, x_));
    visited[y_][x_] = 1;
    graph[y_][x_] = flag;

    while(!q_.empty()){
        int temp_y = q_.front().first;
        int temp_x = q_.front().second;
        q_.pop();

        for(int i = 0; i < 4; i++){
            int new_x = dx[i] + temp_x;
            int new_y = dy[i] + temp_y;
            if(new_x >= 0 && new_x < dimension && new_y >= 0 && new_y < dimension && visited[new_y][new_x] == 0 && graph[new_y][new_x] == 1){
                q_.push(make_pair(new_y, new_x));
                visited[new_y][new_x] = 1;
                graph[new_y][new_x] = flag;
            }
        }
    }
}

int BFS_bridge(int y_, int x_, int my_flag){
    queue<pair<int, int>> q_;
    q_.push(make_pair(y_, x_));
    visited[y_][x_] = 0;

    while(!q_.empty()){
        int temp_y = q_.front().first;
        int temp_x = q_.front().second;
        q_.pop();

        for(int i = 0; i < 4; i++){
            int new_x = dx[i] + temp_x;
            int new_y = dy[i] + temp_y;
            if(new_x >= 0 && new_x < dimension && new_y >= 0 && new_y < dimension && visited[new_y][new_x] == 0){
                if(graph[new_y][new_x] == 0){
                    visited[new_y][new_x] = visited[temp_y][temp_x] + 1;
                    q_.push(make_pair(new_y, new_x));
                }
                else if(graph[new_y][new_x] != my_flag){
                    return visited[temp_y][temp_x];
                }
            }
        }
    }

    return 1000;

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int shortest_bridge = 1000;
    cin >> dimension;

    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            cin >> graph[y][x];
        }
    }

    memset(visited, 0, sizeof(visited));
    int mark = -1;

    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            if(graph[y][x] == 1 && visited[y][x] == 0){
                BFS_locate(y, x, mark);
                mark -= 1;
            }
        }
    }

    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            if(graph[y][x] != 0){
                shortest_bridge = min(shortest_bridge, BFS_bridge(y,x,graph[y][x]));
                memset(visited, 0, sizeof(visited));
            }
        }
    }

    cout << shortest_bridge;


}

