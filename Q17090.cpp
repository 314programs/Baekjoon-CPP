#include <bits/stdc++.h>
using namespace std;

int save_location[500][500];
int visited[500][500];
//For memoization
int can_go[500][500];
char graph[500][500];
int height, width;

int solve(int x, int y){
    int ny = y, nx = x;

    if(graph[y][x] == 'D') ny++;
    if(graph[y][x] == 'U') ny--;
    if(graph[y][x] == 'R') nx++;
    if(graph[y][x] == 'L') nx--;
    
    //Escapes
    if(ny < 0 || ny >= height || nx < 0 || nx >= width){
        can_go[y][x] = 1;
    }
    //Continues travelling
    else if(visited[ny][nx] == 0){
        visited[ny][nx] = 1;
        can_go[y][x] = solve(nx, ny);
    }
    //If it is confirmed that escape is possible... just return the said value and save it
    else if(can_go[ny][nx] != 0){
        can_go[y][x] = can_go[ny][nx];
    }
    
    //Else... can_go is at 0 and unmodified meaning it cannot escape
    return can_go[y][x];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(visited, 0, sizeof(visited));
    memset(can_go, 0, sizeof(can_go));

    cin >> height >> width;
    cin.ignore();

    for(int y = 0; y < height; y++){
        string temp;
        getline(cin, temp);
        for(int x = 0; x < width; x++){
            graph[y][x] = temp[x];
        }
    }

    int ans = 0;
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            //For each unvisited element
            if(visited[y][x] == 0){
                visited[y][x] = 1;
                solve(x, y);
            }
            ans += can_go[y][x];
        }
    }

    cout << ans;

}
