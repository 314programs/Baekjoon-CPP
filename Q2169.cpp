#include <bits/stdc++.h>
using namespace std;
#define MIN -2000000000

int graph[1000][1000];
int visited[1000][1000];
//Y, X, direction coming from
int DP[1000][1000][3];
int height, width;

int dx[4] = {0,1,-1};
int dy[4] = {1,0,0};

int solve(int x, int y, int from){
    //Memoization
    if(DP[y][x][from] != MIN) return DP[y][x][from];
    if(x == width-1 && y == height-1) return graph[y][x];

    int &ans = DP[y][x][from];

    for(int i = 0; i < 3; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < width && ny >= 0 && ny < height && visited[ny][nx] == false){
            //Cannot go to this space anymore
            visited[ny][nx] = true;
            //Find maximum
            ans = max(solve(nx, ny, i) + graph[y][x], ans);
            visited[ny][nx] = false;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> height >> width;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cin >> graph[i][j];
            for(int k = 0; k < 3; k++){
                DP[i][j][k] = MIN;
            }
        }
    }

    memset(visited, false, sizeof(visited));
    //Make sure not to visited start again
    visited[0][0] = true;
    cout << solve(0, 0, 0) << "\n";

}
