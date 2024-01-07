#include <bits/stdc++.h>
using namespace std;

vector<int> connections[50001];
int depth[50001];
int parent[50001];

//U is deeper
int LCA(int u, int v){
    if(depth[u] < depth[v]){
        swap(u, v);
    }
    while(depth[u] > depth[v]){
        u = parent[u];
    }
    while(u != v){
        u = parent[u];
        v = parent[v];
    }
    return u;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int node_cnt;
    cin >> node_cnt;
    
    //No directions specified
    for(int i = 0; i < node_cnt-1; i++){
        int a, b;
        cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    parent[1] = -1;
    queue<int> q;
    q.push(1);
    
    //BFS to find depth
    while(!q.empty()){
        int current = q.front();
        q.pop();
        
        for(auto ch: connections[current]){
            if(depth[ch] != -1) continue;
            depth[ch] = depth[current] + 1;
            q.push(ch);
            parent[ch] = current;
        }
    }

    int tc;
    cin >> tc;

    while(tc--){
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
}
