//Similar to 17141... but now 2 doesn't count as an empty space
#include <bits/stdc++.h>
using namespace std;

int graph[50][50];
int visited[50][50];

struct point{
    int x, y;
};
vector<point> place_points;

int dimension, place_count;
int ans = -1;
int empty_count = 0;
int comb_check[2500];
int combination[2500];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int bfs(){
    int time = 0;
    int current_empty = empty_count;
    queue<point> q;
    memset(visited, -1, sizeof(visited));
    for(int i = 0; i < place_count; i++){
        q.push(place_points[combination[i]]);
        visited[place_points[combination[i]].y][place_points[combination[i]].x] = 0;
    }

    while(!q.empty() && current_empty != 0){
        point temp = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = temp.y + dy[i];
            int nx = temp.x + dx[i];
            if(ny >= 0 && ny < dimension && nx >= 0 && nx < dimension && visited[ny][nx] == -1 && graph[ny][nx] != 1){
                if(graph[ny][nx] == 0) current_empty--;
                visited[ny][nx] = visited[temp.y][temp.x] + 1;
                time = max(time, visited[ny][nx]);
                q.push({nx, ny});
            }
        }
    }
    if(current_empty == 0) return time;
    else return -1;
}

void comb(int s, int idx, int prev){
    if(idx == place_count){
        int temp = bfs();
        if(temp != -1 && (ans == -1 || temp < ans)){
            ans = temp;
        }
        return;
    }

    for(int i = 0; i < s; i++){
        if(comb_check[i] == -1 && i > prev){
            comb_check[i] = 1;
            combination[idx] = i;
            comb(s, idx+1, i);
            comb_check[i] = -1;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> dimension >> place_count;

    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            cin >> graph[y][x];
            if(graph[y][x] == 2){
                place_points.push_back({x, y});
            }
            else if(graph[y][x] == 0){
                empty_count++;
            }
        }
    }

    int place_size = place_points.size();
    memset(comb_check, -1, sizeof(comb_check));
    comb(place_size, 0, -1);
    cout << ans;
}
