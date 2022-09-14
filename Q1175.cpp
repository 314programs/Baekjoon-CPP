#include <bits/stdc++.h>
using namespace std;

char graph[50][50];
//Indi, y, x, prev
//Indi = 0: None visited
//Indi = 1: c1 visited
//Indi = 2: c2 visited
//Indi = 3: finish
int visited[4][50][50][4];

struct node{
    int x, y;
};

struct point{
    int x, y, prev, indi;
};

int height, width;
node start;
node c1 = {-1, -1};
node c2 = {-1, -1};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> height >> width;
    
    //Input
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            cin >> graph[y][x];
            if(graph[y][x] == 'S'){
                start = {x, y};
            }
            if(graph[y][x] == 'C'){
                if(c1.x == -1) c1 = {x, y};
                else c2 = {x, y};
            }
        }
    }

    queue<point> q;
    int ans = -1;
    memset(visited, -1, sizeof(visited)); 
    
    //Can be every direction for start
    for(int i = 0; i < 4; i++){
        visited[0][start.y][start.x][i] = 0;
        q.push({start.x, start.y, i, 0});
    }

    while(!q.empty()){
        auto current = q.front();
        q.pop();

        if(current.indi == 3){
            ans = visited[current.indi][current.y][current.x][current.prev];
            break;
        }

        for(int i = 0; i < 4; i++){
            if(i == current.prev) continue;
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            int prev_dist = visited[current.indi][current.y][current.x][current.prev];
            int indicator = current.indi;
            
            if(nx >= 0 && nx < width && ny >= 0 && ny < height && graph[ny][nx] != '#'){
                //Instead of writing 30 lines of code separatng c1 and c2... this is simpler!
                //Add the indicator instead of changing it
                if(nx == c1.x && ny == c1.y && indicator != 1){
                    indicator += 1;
                }
                else if(nx == c2.x && ny == c2.y && indicator != 2){
                    indicator += 2;
                }

                if(visited[indicator][ny][nx][i] == -1){
                    visited[indicator][ny][nx][i] = prev_dist + 1;
                    q.push({nx, ny, i, indicator});
                }
            }
        }
    }

    cout << ans;


}
