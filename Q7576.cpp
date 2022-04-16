#include <bits/stdc++.h>
using namespace std;

int graph[1001][1001];
int visited[1001][1001];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int height, width;
    //Make pair queue
    queue<pair<int, int>> q;
    cin >> width >> height;

    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){
            int temp;
            cin >> temp;
            graph[h][w] = temp;
            visited[h][w] = -1;
            if(temp == 1){
                q.push(make_pair(h, w));
                visited[h][w] = 0;
            } 
        }
    }

    while(!q.empty()){
        int temp_x = q.front().second;
        int temp_y = q.front().first;
        q.pop();

        for(int i = 0; i < 4; i++){
            int X = temp_x + dx[i];
            int Y = temp_y + dy[i];
            if(X <= width && X >= 0 && Y <= height && Y >= 0 && visited[Y][X] == -1 && graph[Y][X] != -1){
                visited[Y][X] = visited[temp_y][temp_x] + 1;
                q.push(make_pair(Y,X));
            }
        }
    }

    int time = 0;
    bool all_ripe = true;
    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){
            time = max(time, visited[h][w]);
            if(visited[h][w] == -1 && graph[h][w] == 0){
                all_ripe = false;
            }
        }
    }

    if(all_ripe){
        cout << time;
    }
    else{
        cout << -1;
    }


}
