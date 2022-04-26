#include <bits/stdc++.h>
using namespace std;

int Dy[4] = {1,-1,0,0};
int Dx[4] = {0,0,1,-1};

int height, width;
int graph[100][100];
int visited[100][100];

void BFS(int x_, int y_){
    queue<pair<int, int>> q_;
    q_.push(make_pair(y_, x_));
    visited[y_][x_] = 1;

    while(!q_.empty()){
        int y = q_.front().first;
        int x = q_.front().second;
        q_.pop();

        for(int i = 0; i < 4; i++){
            int new_y = y + Dy[i];
            int new_x = x + Dx[i];
            if(new_y >= 0 && new_y < height && new_x >= 0 && new_x < width && visited[new_y][new_x] == 0 && graph[new_y][new_x] != -1){
                visited[new_y][new_x] = visited[y][x] + 1;
                q_.push(make_pair(new_y, new_x));
            }
        }
    }

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> height >> width;
    cin.ignore();

    for(int i = 0; i < height; i++){
        string temp;
        getline(cin, temp);
        for(int j = 0; j < width; j++){
            if(temp[j] - '0' == 1){
                graph[i][j] = 0;
            }
            else{
                graph[i][j] = -1;
            }
            visited[i][j] = 0;
        }
    }

    BFS(0,0);
    cout << visited[height-1][width-1];
    
}

