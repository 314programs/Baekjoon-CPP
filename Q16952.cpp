#include <bits/stdc++.h>
using namespace std;

int dimension;
int graph[10][10];
//current num, chess piece used, y, x, changed
int visited[101][3][10][10][301];

int dy1[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dx1[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int dy2[4] = {0,0,1,-1};
int dx2[4] = {1,-1,0,0};

int dy3[4] = {1,1,-1,-1};
int dx3[4] = {1,-1,1,-1};

struct node{
    int x, y, current_num, piece, changed;
};
queue<node> q;

bool check(int x, int y){
    return (x >= 0 && x < dimension && y >= 0 && y < dimension);
}

void is(node current, int next_dist, int nx, int ny){
    if(graph[ny][nx] == current.current_num + 1){
        current.current_num += 1;
    }
    if(visited[current.current_num][current.piece][ny][nx][current.changed] == -1){
        visited[current.current_num][current.piece][ny][nx][current.changed] = next_dist;
        q.push({nx, ny, current.current_num, current.piece, current.changed});
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> dimension;

    pair<int, int> start;
    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            cin >> graph[y][x];
            if(graph[y][x] == 1){
                start = make_pair(x, y);
            }
        }
    }

    int ans = -1;
    int min_change = 100000000;
    memset(visited, -1, sizeof(visited));
    for(int i = 0; i < 3; i++){
        q.push({start.first, start.second, 1, i});
        visited[1][i][start.second][start.first][0] = 0;
    }   
    
    while(!q.empty()){
        const node current = q.front();
        q.pop();

        int next_dist = visited[current.current_num][current.piece][current.y][current.x][current.changed] + 1;
        if(current.current_num == dimension*dimension){
            if(ans == -1){
                ans = next_dist-1;
                min_change = current.changed;
            }
            if(ans == next_dist-1){
                min_change = min(min_change, current.changed);
            }
        }

        for(int i = 0; i < 3; i++){
            if(i == current.piece) continue;
            if(current.changed + 1 > current.current_num * 3) continue;

            if(visited[current.current_num][i][current.y][current.x][current.changed+1] == -1){
                visited[current.current_num][i][current.y][current.x][current.changed+1] = next_dist;
                q.push({current.x, current.y, current.current_num, i, current.changed+1});
            }
        }

        //Knight
        if(current.piece == 0){
            for(int i = 0; i < 8; i++){
                int nx = dx1[i] + current.x;
                int ny = dy1[i] + current.y;
                if(check(nx, ny)){
                    is(current, next_dist, nx, ny);
                }
            }
        }

        //Rook
        if(current.piece == 1){
            for(int i = 0; i < 4; i++){
                for(int j = 1;; j++){
                    int nx = current.x + (dx2[i] * j);
                    int ny = current.y + (dy2[i] * j);
                    if(check(nx, ny)){
                        is(current, next_dist, nx, ny);
                    }
                    else break;
                }
            }
        }

        //Bishop
        if(current.piece == 2){
            for(int i = 0; i < 4; i++){
                for(int j = 1;; j++){
                    int nx = current.x + (dx3[i] * j);
                    int ny = current.y + (dy3[i] * j);
                    if(check(nx, ny)){
                        is(current, next_dist, nx, ny);
                    }
                    else break;
                }
            }
        }
    }
    
    cout << ans << " " << min_change;

}
