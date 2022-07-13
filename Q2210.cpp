#include <bits/stdc++.h>
using namespace std;

int visited[1000000];
vector<vector<int>> graph(5, vector<int> (5));

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int solved(int x, int y, int idx, string current_num){
    int ans = 0;
    if(idx == 6){
        if(visited[stoi(current_num)] == 0){
            visited[stoi(current_num)] = 1;
            ans++;
        }
        return ans;
    }
    
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && ny < 5 && nx >= 0 && nx < 5){
            ans += solved(nx, ny, idx+1, current_num + to_string(graph[ny][nx]));
        }
    }
    
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            cin >> graph[y][x];
        }
    }
    
    memset(visited, 0, sizeof(visited));
    int ans = 0;
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            ans += solved(x, y, 1, to_string(graph[y][x]));
        }
    }
    cout << ans;

}
