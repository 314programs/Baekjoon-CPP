#include <bits/stdc++.h>
using namespace std;

int graph[500][500];
int visited[500][500];
int ans = 0;
int height, width;

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

//All shapes besides T can be made by this function that looks like a BFS
void calc(int x, int y, int sum_, int count_){
    if(x < 0 || x == width || y < 0 || y == height || visited[y][x] == 1) return;

    if(count_ == 4){
        ans = max(ans, sum_);
        return;
    }
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        calc(x+dx[i], y+dy[i], sum_+graph[y+dy[i]][x+dx[i]], count_+1);
    }
    //This is not a BFS since the visited space can be visited again
    visited[y][x] = 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    
    cin >> height >> width;


    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            cin >> graph[y][x];
        }
    }
    
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            //All other blocks
            calc(x, y, 0, 0);
            //For all shapes of T
            if(y - 1 >= 0 && x + 2 < width){
                ans = max(ans, graph[y][x] + graph[y][x+1] + graph[y-1][x+1] + graph[y][x+2]);
            }
            if(y + 2 < height && x + 1 < width){
                ans = max(ans, graph[y][x] + graph[y+1][x] + graph[y+1][x+1] + graph[y+2][x]);
            }
            if(x + 2 < width && y + 1 < height){
                ans = max(ans, graph[y][x] + graph[y][x+1] + graph[y+1][x+1] + graph[y][x+2]);
            }
            if(x - 1 >= 0 && y + 2 < height){
                ans = max(ans, graph[y][x] + graph[y+1][x] + graph[y+1][x-1] + graph[y+2][x]);
            }
        }
    }

    cout << ans;

}


