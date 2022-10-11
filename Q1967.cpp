#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[10001];
int visited[10001];

void BFS(int start_){
    queue<pair<int, int>> q_;
    q_.push(make_pair(0, start_));
    visited[start_] = 0;

    while(!q_.empty()){
        int distance = q_.front().first;
        int current_node = q_.front().second;
        q_.pop();

        for(pair<int, int> ch: graph[current_node]){
            int next_dist = ch.first + distance;
            int next_node = ch.second;
            if(visited[next_node] == -1){
                visited[next_node] = next_dist;
                q_.push(make_pair(next_dist, next_node));
            }
        }

    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int nodes;
    cin >> nodes;

    for(int i = 0; i < nodes-1; i++){
        int parent_, child_, dist_;
        cin >> parent_ >> child_ >> dist_;
        //Distance first!
        graph[parent_].push_back(make_pair(dist_, child_));
        graph[child_].push_back(make_pair(dist_, parent_));
    }

    memset(visited, -1, sizeof(visited));
    BFS(1);

    int max_dist = 0;
    int max_node = 0;

    for(int i = 1; i <= nodes; i++){
        if(visited[i] > max_dist){
            max_dist = visited[i];
            max_node = i;
        }
    }

    memset(visited, -1, sizeof(visited));
    BFS(max_node);

    int ans = 0;
    for(int i = 1; i <= nodes; i++){
        ans = max(ans, visited[i]);
    }

    cout << ans;

}

