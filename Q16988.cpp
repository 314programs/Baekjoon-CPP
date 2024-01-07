#include <bits/stdc++.h>
using namespace std;
int height, width;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

struct point{
    int x, y;
};

int bfs(point p, vector<vector<int>> & graph){
    bool empty_space = false;
    int group_num = 1;

    deque<point> q;
    q.push_back(p);
    graph[p.y][p.x] = -1;
    
    //Check how many are trapped
    while(!q.empty()){
        point temp = q.front();
        q.pop_front();

        for(int i = 0; i < 4; i++){
            int ny = temp.y + dy[i];
            int nx = temp.x + dx[i];
            if(ny >= 0 && ny < height && nx >= 0 && nx < width){
                if(graph[ny][nx] == 0){
                    empty_space = true;
                }
                else if(graph[ny][nx] == 2){
                    q.push_back({nx, ny});
                    graph[ny][nx] = -1;
                    group_num++;
                }
            }
        }
    }

    if(empty_space == true) return 0;
    else return group_num;
}

int solve(vector<vector<int>> graph){
    int ans = 0;
    //Total count of trapped enemies
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(graph[y][x] == 2){
                ans += bfs({x, y}, graph);
            }
        }
    }

    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> height >> width;
    int area = height*width;

    vector<vector<int>> graph(height, vector<int> (width));
    vector<point> coords(area);

    int idx = 0;
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            coords[idx++] = {x, y};
            cin >> graph[y][x];
        }
    }


    int ans = 0;
    
    //Check for each case...
    for(int i = 0; i < area - 1; i++){
        for(int j = i+1; j < area; j++){
            if(graph[coords[i].y][coords[i].x] == 0 && graph[coords[j].y][coords[j].x] == 0){
                graph[coords[i].y][coords[i].x] = 1;
                graph[coords[j].y][coords[j].x] = 1;
                ans = max(solve(graph), ans);
                graph[coords[i].y][coords[i].x] = 0;
                graph[coords[j].y][coords[j].x] = 0;
            }
        }
    }

    cout << ans;

}
