#include <bits/stdc++.h>
using namespace std;

//rotation, z, y, x
int graph[4][5][5][5];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int ans = -1;
//Both are decided by z axis
//Rotation
int p_list[5] = {0, 0, 0, 0, 0};
//Floor combination
vector<int> floor_list = {0, 1, 2, 3, 4};

struct coord{
    int x, y, z;
};

//BFS to find out if maze can be escaped + spaces it took to escape
int bfs(){
    if(graph[p_list[0]][floor_list[0]][0][0] != 1) return -1;
    int visited[5][5][5];
    memset(visited, 0, sizeof(visited));

    deque<coord> q;
    q.push_back({0, 0, 0});

    while(!q.empty()){
        coord temp = q.front();
        q.pop_front();

        for(int i = 0; i < 6; i++){
            int nx = temp.x + dx[i];
            int ny = temp.y + dy[i];
            int nz = temp.z + dz[i];

            if(nx >= 0 && ny >= 0 && nz >= 0 && nx < 5 && ny < 5 && nz < 5 && visited[nz][ny][nx] == 0 && graph[p_list[nz]][floor_list[nz]][ny][nx] == 1){
                visited[nz][ny][nx] = visited[temp.z][temp.y][temp.x] + 1;
                q.push_back({nx, ny, nz});
            }
        }
    }

    if(visited[4][4][4] == 0) return -1;
    else return visited[4][4][4];
}

void permu(int idx){
    if(idx == 5){
        int temp = bfs();
        if(temp != -1 && (ans == -1 || ans > temp)){
            ans = temp;
        }
        return;
    }

    for(int i = 0; i < 4; i++){
        p_list[idx] = i;
        permu(idx+1);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    //Store rotated floors in a list
    for(int j = 0; j < 5; j++){
        int floor[5][5];
        for(int y = 0; y < 5; y++){
            for(int x = 0; x < 5; x++){
                cin >> floor[y][x];
                graph[0][j][y][x] = floor[y][x];
            }
        }

        int clockwise[5][5];
        for(int i = 0; i < 3; i++){
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    clockwise[y][x] = floor[4-x][y];
                }
            }

            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    graph[i+1][j][y][x] = clockwise[y][x];
                    floor[y][x] = clockwise[y][x];
                }
            }
        }
    }

    do{
        permu(0);
    }
    //Make all permutation for all possible floor placements
    while(next_permutation(floor_list.begin(), floor_list.end()));
    cout << ans;
}
