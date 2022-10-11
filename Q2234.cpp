#include <bits/stdc++.h>
using namespace std;

//THIS ORDER IS IMPORTANT
//This marks the opposing walls
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int graph[50][50];
int visited[50][50];
int area[50];
int width, height;

struct point{
    int x, y;
};

//Mark each room
int room_area(point start, int idx){
    queue<point> q;
    q.push(start);
    visited[start.y][start.x] = idx;
    int total_area = 1;

    while(!q.empty()){
        point temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int ny = temp.y + dy[i];
            int nx = temp.x + dx[i];
            //(graph[ny][nx] & (1 << i)) is to mark if there is no wall
            if(ny >= 0 && ny < height && nx >= 0 && nx < width && (graph[ny][nx] & (1 << i)) == 0 && visited[ny][nx] == -1){
                visited[ny][nx] = idx;
                total_area++;
                q.push({nx, ny});
            }
        }
    }
    area[idx] = total_area;
    return total_area;
}

//Combine area of different rooms
int comb_room(point start){
    set<int> s;
    int current_area = area[visited[start.y][start.x]];
    for(int i = 0; i < 4; i++){
        int ny = start.y + dy[i];
        int nx = start.x + dx[i];
        if(ny >= 0 && ny < height && nx >= 0 && nx < width && visited[ny][nx] != visited[start.y][start.x]){
            s.insert(area[visited[ny][nx]]);
        }
    }
    int temp = 0;
    for(auto ch: s){
        temp = max(temp, ch);
    }
    return current_area + temp;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> width >> height;

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            cin >> graph[y][x];
        }
    }


    memset(visited, -1, sizeof(visited));
    int idx = 0;
    int max_area = 0;
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(visited[y][x] == -1){
                max_area = max(max_area, room_area({x, y}, idx++));
            }
        }
    }

    int max_comb_a = 0;
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            max_comb_a = max(max_comb_a, comb_room({x, y}));
        }
    }

    cout << idx << "\n" << max_area << "\n" << max_comb_a;


}
