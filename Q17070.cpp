#include <bits/stdc++.h>
using namespace std;

int dimension;
int dy[3] = {0, 1, 1};
int dx[3] = {1, 0, 1};

int solve(vector<vector<int>> & graph, int direction, int x, int y){
    int ans = 0;
    if(x == dimension-1 && y == dimension-1){
        return 1;
    }
    for(int i = 0; i < 3; i++){
        if(direction == 0 && i == 1) continue;
        if(direction == 1 && i == 0) continue;

        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < dimension && ny >= 0 && ny < dimension && graph[ny][nx] == 0){
            if(i == 2){
                if(graph[ny-1][nx] == 0 && graph[ny][nx-1] == 0){
                    ans += solve(graph, i, nx, ny);
                }
            }
            else{
                ans += solve(graph, i, nx, ny);
            }
        }
    }
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> dimension;

    vector<vector<int>> graph (dimension, vector<int> (dimension));
    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            cin >> graph[y][x];
        }
    }

    cout << solve(graph, 0, 1, 0);
}
