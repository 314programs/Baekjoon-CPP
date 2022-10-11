#include <bits/stdc++.h>
using namespace std;

int dimension;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int visited[100][100];

struct point{
    int x, y;
};

bool check(int max_dif, vector<vector<int>> & graph){
    //i = min, i + max_dif = max;
    for(int i = 0; i + max_dif <= 200; i++){
        deque<point> dq;
        memset(visited, 0, sizeof(visited));

        if(graph[0][0] < i || graph[0][0] > max_dif + i) continue;

        dq.push_back({0, 0});
        visited[0][0] = 1;

        while(!dq.empty()){
            point current = dq.front();
            dq.pop_front();

            if(current.x == dimension - 1 && current.y == dimension - 1){
                return true;
            }
            
            for(int j = 0; j < 4; j++){
                int nx = dx[j] + current.x;
                int ny = dy[j] + current.y;
                if(nx >= 0 && nx < dimension && ny >= 0 && ny < dimension && visited[ny][nx] == 0){
                    if(graph[ny][nx] <= (i + max_dif) && graph[ny][nx] >= i){
                        visited[ny][nx] = 1;
                        dq.push_back({nx, ny});
                    }
                }
            }
        }
    }
    
    return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> dimension;

    vector<vector<int>> graph(dimension, vector<int> (dimension));

    int min_ = 201, max_ = -1;
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            cin >> graph[i][j];
            min_ = min(min_, graph[i][j]);
            max_ = max(max_, graph[i][j]);
        }
    }
    
    //Use binary search to find the max difference(mid) and minimise it by checking bfs
    int left = 0, right = max_ - min_;
    int ans = 0;
    while(left <= right){
        int mid = (left+right)/2;
        if(check(mid, graph) == true){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    cout << ans;

}
