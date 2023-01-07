#include <bits/stdc++.h>
//Forgot how to use DFS
using namespace std;

vector<int> graph[1001];
int visited[1001];

void bfs(int start){
    queue<int> q_;
    q_.push(start);
    visited[start] = 1;

    while(!q_.empty()){
        int temp = q_.front();
        q_.pop();
        cout << temp << " ";

        for(int i = 0; i < graph[temp].size(); i++){
            int next = graph[temp][i];
            if(visited[next] == 0){
                visited[next] = 1;
                q_.push(next);
            }
        }
    }

}

void dfs(int node){
    visited[node] = 1;
    cout << node << " ";

    for(int i = 0; i < graph[node].size(); i++){
        int next = graph[node][i];
        if(visited[next] == 0){
            dfs(next);
        }
    }


}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int node_num, connection_num, start;
    cin >> node_num >> connection_num >> start;

    for(int i = 0; i <connection_num; i++){
        int a, b;
        cin >> a >> b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= node_num; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    
    //Reset
    memset(visited, 0, 1001*4);
    dfs(start);
    cout << "\n";
    memset(visited, 0, 1001*4);
    bfs(start);


}
