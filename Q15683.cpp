#include <bits/stdc++.h>
using namespace std;

//Down, Up, Right, left
int height, width;
vector<int> dy = {1, -1, 0, 0};
vector<int> dx = {0, 0, 1, -1};
map <int, vector<vector<int>>> m;
int ans = 10000;

struct camera{
    int x, y, camera_num;
};
vector<camera> cameras;

vector<vector<int>> mark_dir(vector<int> direction, vector<vector<int>> graph, int idx){
    camera c = cameras[idx];
    for(auto ch: direction){
        int multi = 1;
        while(true){
            int ny = c.y + (dy[ch] * multi);
            int nx = c.x + (dx[ch] * multi);
            if(ny >= 0 && ny < height && nx >= 0 && nx < width && graph[ny][nx] != 6){
                if(graph[ny][nx] == 0) graph[ny][nx] = -1;
            }
            else{
                break;
            }
            multi++;
        }
    }

    return graph;
}

int check(vector<vector<int>> & graph){
    int no_camera = 0;
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(graph[y][x] == 0){
                no_camera++;
            }
        }
    }
    return no_camera;
}

void solve(vector<vector<int>> graph, int idx, int camera_count){
    if(idx == camera_count){
        ans = min(ans, check(graph));
        return;
    }
    for(auto ch: m[cameras[idx].camera_num]){
        solve(mark_dir(ch, graph, idx), idx+1, camera_count);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    m[1] = {{0}, {1}, {2}, {3}};
    m[2] = {{0, 1}, {2, 3}};
    m[3] = {{1, 2}, {2, 0}, {0, 3}, {3, 1}};
    m[4] = {{0,1,2}, {1,2,3}, {2,3,0}, {3,0,1}};
    m[5] = {{0,1,2,3}};

    cin >> height >> width;

    vector<vector<int>> graph (height, vector<int> (width));

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            cin >> graph[y][x]; 
            if(graph[y][x] != 0 && graph[y][x] != 6){
                cameras.push_back({x, y, graph[y][x]});
            }
        }
    }

    solve(graph, 0, cameras.size());
    cout << ans;

}
