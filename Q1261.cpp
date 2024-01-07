#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int width, height;
    cin >> width >> height;
    cin.ignore();

    int graph[100][100];

    for(int y = 0; y < height; y++){
        string temp;
        getline(cin, temp);
        for(int x = 0; x < width; x++){
            graph[y][x] = temp[x] - '0';
        }
    }

    struct triplet{
        int y;
        int x;
        int wall;
    };

    int dy[4] = {1,-1,0,0};
    int dx[4] = {0,0,1,-1};

    deque<triplet> dq;
    int visited[100][100];
    memset(visited, -1, sizeof(visited));
    
    visited[0][0] = 0;
    dq.push_back({0,0,0});

    while(!dq.empty()){
        int temp_y = dq.front().y;
        int temp_x = dq.front().x;
        int temp_wall = dq.front().wall;
        dq.pop_front();

        for(int i = 0; i < 4; i++){
            int y_ = dy[i] + temp_y;
            int x_ = dx[i] + temp_x;

            if(y_ <  height && y_ >= 0 && x_ < width && x_ >= 0 && visited[y_][x_] == -1){
                if(graph[y_][x_] == 0){
                    visited[y_][x_] = temp_wall;
                    dq.push_front({y_, x_, temp_wall});
                }
                else{
                    visited[y_][x_] = temp_wall+1;
                    dq.push_back({y_, x_, temp_wall+1});
                }
            }
        }
    }

    cout << visited[height-1][width-1];

}

