#include <bits/stdc++.h>
using namespace std;
vector<int> graph[2000];
int visited[1001];

void BFS(int node_num){
    queue<int> q;
    q.push(node_num);
    visited[node_num] = 1;
    while(!q.empty()){
        int temp = q.front();
        q.pop();

        for(auto ch: graph[temp]){
            if(visited[ch] != 1){
                q.push(ch);
                visited[ch] = 1;
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int nodes, connections;
    cin >> nodes >> connections;
    int count_ = 0;

    for(int i = 0; i < connections; i++){
        int a,b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(visited, 0, sizeof(visited));

    for(int i = 1; i <= nodes; i++){
        if(visited[i] != 1){
            BFS(i);
            count_ += 1;
        }
    }

    cout << count_;

}

