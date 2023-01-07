#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int node_num;
    cin >> node_num;

    int visited[100001];
    vector<int> graph_[100001];
    memset(visited, -1, sizeof(visited));

    for(int i = 0; i < node_num - 1; i++){
        int a_, b_;
        cin >> a_ >> b_;
        graph_[a_].push_back(b_);
        graph_[b_].push_back(a_);
    }

    queue<int> q_;
    visited[1] = 0;
    q_.push(1);

    while(!q_.empty()){
        int temp_ = q_.front(); q_.pop();
        for(int ch: graph_[temp_]){
            if(visited[ch] == -1){
                visited[ch] = temp_;
                q_.push(ch);
            }
        }
    }

    for(int i = 2; i <= node_num; i++){
        cout << visited[i] << "\n";
    }

}

