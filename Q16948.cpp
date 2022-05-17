#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int dimension;
    cin >> dimension;

    int current_x, current_y, wanted_x, wanted_y;
    cin >> current_x >> current_y >> wanted_x >> wanted_y;

    int dx[6] = {-2, -2, 0, 0, 2, 2};
    int dy[6] = {-1, 1, -2, 2, -1, 1};
    int visited[dimension][dimension];

    queue<pair<int, int>> q_;
    memset(visited, -1, sizeof(visited));
    q_.push(make_pair(current_y, current_x));
    visited[current_y][current_x] = 0;

    while(!q_.empty()){
        int temp_x = q_.front().second;
        int temp_y = q_.front().first;
        q_.pop();

        for(int i = 0; i < 6; i++){
            int ny = temp_y + dy[i];
            int nx = temp_x + dx[i];

            if(ny >= 0 && ny < dimension && nx >= 0 && nx < dimension && visited[ny][nx] == -1){
                visited[ny][nx] = visited[temp_y][temp_x] + 1;
                q_.push(make_pair(ny, nx));
            }
        }
    }

    cout << visited[wanted_y][wanted_x];

}


 
