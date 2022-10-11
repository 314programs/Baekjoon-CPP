#include <bits/stdc++.h>
using namespace std;

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int height, width;
int ans;

void solve(vector<vector<char>> & graph, int x, int y, int movement, int empty_space){
    //Count empty spaces
    if(empty_space == 0){
        if(ans == -1 || ans > movement) ans = movement;
        return;
    }

    for(int i = 0; i < 4; i++){
        //For each direction go until bumping into wall or graph dimensions
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        while(ny >= 0 && ny < height && nx >= 0 && nx < width && graph[ny][nx] == '.'){
            graph[ny][nx] = '#';
            empty_space--;
            ny += dy[i];
            nx += dx[i];
        }
        ny -= dy[i];
        nx -= dx[i];
        
        //If ball has moved
        if(!(ny == y && nx == x)){
            solve(graph, nx, ny, movement+1, empty_space);
        }
        
        //Remove spots left by ball
        while(!(ny == y && nx == x)){
            graph[ny][nx] = '.';
            empty_space++;
            ny -= dy[i];
            nx -= dx[i];
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int count = 1;
    //!cin.eof()
    while(cin >> height >> width){
        vector<vector<char>> graph (height, vector<char> (width));
        int empty_space = 0;
        ans = -1;
        for(int y = 0; y < height; y++){
            for(int x = 0; x < width; x++){
                cin >> graph[y][x];
                if(graph[y][x] == '.') empty_space++;
            }
        }


        for(int y = 0; y < height; y++){
            for(int x = 0; x < width; x++){
                if(graph[y][x] == '.'){
                    //Set starting point as wall
                    graph[y][x] = '#';
                    solve(graph, x, y, 0, empty_space-1);
                    graph[y][x] = '.';
                }
            }
        }

        cout << "Case " << count << ": " << ans << "\n";
        count += 1;
    }
}
