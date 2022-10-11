#include <bits/stdc++.h>
using namespace std;

int visited[100001];
//Distance goes first!
vector<pair<int, int>> graph_[100001];

void BFS(int start_){
    queue<pair<int, int>> q_;
    q_.push(make_pair(0, start_));
    visited[start_] = 0;

    while(!q_.empty()){
        int temp_dist = q_.front().first; 
        int temp_node = q_.front().second;
        q_.pop();
        for(pair<int, int> ch: graph_[temp_node]){
            if(visited[ch.second] == -1){
                visited[ch.second] = temp_dist + ch.first;
                q_.push(make_pair(temp_dist + ch.first, ch.second));
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int node_num;
    cin >> node_num;

    memset(visited, -1, sizeof(visited));

    for(int i = 0; i < node_num; i++){
        int start_node;
        cin >> start_node;

        while(true){
            int node_, dist_;
            cin >> node_;
            if(node_ == -1){
                break;
            }
            cin >> dist_;
            graph_[start_node].push_back(make_pair(dist_, node_));
        }
    }

    BFS(1);
    int furthest_node;
    int furthest_dist = 0;
    for(int i = 1; i <= node_num; i++){
        if(furthest_dist < visited[i]){
            furthest_dist = visited[i];
            furthest_node = i;
        }
    }
    
    memset(visited, -1, sizeof(visited));
    BFS(furthest_node);
    int far_ = 0;
    for(int i = 1; i <= node_num; i++){
        far_ = max(far_, visited[i]);
    }
    cout << far_;

}

