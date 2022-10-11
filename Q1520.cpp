#include <bits/stdc++.h>
using namespace std;

int DP[500][500];
int a[500][500];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int height, width;

int solve(int x, int y, int prev){
    //Reached the end, there is a path
    if(x == width-1 && y == height-1){
        return 1;
    }

    DP[y][x] = 0;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(nx >= 0 && nx < width && ny >= 0 && ny < height && a[ny][nx] < prev){
            if(DP[ny][nx] != -1){
                //Memoization
                DP[y][x] += DP[ny][nx];
            }
            else{
                //Don't have number of path yet
                DP[y][x] += solve(nx, ny, a[ny][nx]);
            }
        }
    }
    return DP[y][x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    cin >> height >> width;
    memset(DP, -1, sizeof(DP));
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cin >> a[i][j];
        }
    }

    cout << solve(0, 0, a[0][0]) << "\n";


}
