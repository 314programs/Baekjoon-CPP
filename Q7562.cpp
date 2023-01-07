#include <bits/stdc++.h>
using namespace std;

int Dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int Dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int dimension;
int graph[300][300];
int visited[300][300];
int end_x, end_y;

void BFS(int x_, int y_){
    queue<pair<int, int>> q_;
    q_.push(make_pair(y_, x_));
    visited[y_][x_] = 0;

    while(!q_.empty()){
        int y = q_.front().first;
        int x = q_.front().second;

        if(y == end_y && x == end_x){
            return;
        }
        q_.pop();

        for(int i = 0; i < 8; i++){
            int new_y = y + Dy[i];
            int new_x = x + Dx[i];
            if(new_y >= 0 && new_y < dimension && new_x >= 0 && new_x < dimension && visited[new_y][new_x] == 0 && graph[new_y][new_x] != -1){
                visited[new_y][new_x] = visited[y][x] + 1;
                q_.push(make_pair(new_y, new_x));
            }
        }
    }

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int testcase;
    cin >> testcase;

    while(testcase--){
        int start_x, start_y;

        cin >> dimension;
        cin >> start_x >> start_y;
        cin >> end_x >> end_y;

        for(int i = 0; i < dimension; i++){
            for(int j = 0; j < dimension; j++){
                visited[i][j] = 0;
            }
        }

        BFS(start_x,start_y);
        cout << visited[end_y][end_x] << "\n";
    }
    
}

