#include <bits/stdc++.h>
using namespace std;

int Dy[8] = {1,-1,0,0,1,-1,1,-1};
int Dx[8] = {0,0,1,-1,1,1,-1,-1};

int height, width;
int graph[50][50];
int visited[50][50];

void BFS(int x_, int y_){
    queue<pair<int, int>> q_;
    q_.push(make_pair(y_, x_));
    visited[y_][x_] = 1;

    while(!q_.empty()){
        int y = q_.front().first;
        int x = q_.front().second;
        q_.pop();

        for(int i = 0; i < 8; i++){
            int new_y = y + Dy[i];
            int new_x = x + Dx[i];
            if(new_y >= 0 && new_y < height && new_x >= 0 && new_x < width && visited[new_y][new_x] != 1 && graph[new_y][new_x] == 1){
                visited[new_y][new_x] = 1;
                q_.push(make_pair(new_y, new_x));
            }
        }
    }

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while(true){
        cin >> width >> height;

        if(width == 0 && height == 0){
            break;
        }

        cin.ignore();
        int sizes_ = 0;

        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                //Remember to reset visited!
                visited[i][j] = 0;
                cin >> graph[i][j];
            }
        }

        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(visited[i][j] != 1 && graph[i][j] == 1){
                    BFS(j, i);
                    sizes_ += 1;
                }
            }
        }

        cout << sizes_ << "\n";
    }
    

}

