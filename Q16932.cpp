#include <bits/stdc++.h>
using namespace std;

int height, width;
int graph[1000][1000];
int areas[1000000];

struct point{
    int x, y;
};

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

//Calculate area of shape and store it in a list
//Mark the group in a specific index
void calc_area(int x, int y, vector<vector<int>> & visited, int idx){
    int count_ = 1;
    deque<point> dq;
    dq.push_back({x, y});
    visited[y][x] = idx;

    while(!dq.empty()){
        point temp = dq.front();
        dq.pop_front();

        for(int i = 0; i < 4; i++){
            int nx = temp.x + dx[i];
            int ny = temp.y + dy[i];
            if(nx >= 0 && nx < width && ny >= 0 && ny < height && visited[ny][nx] == -1 && graph[ny][nx] == 1){
                visited[ny][nx] = idx;
                count_++;
                dq.push_back({nx, ny});
            }
        }
    }
    areas[idx] = count_;
}

//Get maximum number of surrounding groups from this point that are different
//Calculate their total area
int max_area(int x, int y, vector<vector<int>> & visited){
    set<int> s;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < width && ny >= 0 && ny < height && visited[ny][nx] != -1 && graph[ny][nx] == 1){
            s.insert(visited[ny][nx]);
        }
    }

    int ans = 1;
    for(auto ch: s){  
        ans += areas[ch];
    }
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> height >> width;
    vector<vector<int>> visited(height, vector<int>(width, -1));

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            cin >> graph[y][x];
        }
    }

    int idx = 0;
    //Group finding for each
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(graph[y][x] == 1 && visited[y][x] == -1){
                calc_area(x, y, visited, idx++);
            }
        }
    }

    int ans = -1;
    //Place point every possible way
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(graph[y][x] == 0) ans = max(ans, max_area(x, y, visited));
        }
    }
    cout << ans;

}
