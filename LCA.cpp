#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
int dist[MAX];
int p[MAX][20];
int log_ = 0;
int timer = 0;
vector<int> connections[MAX];

//These values can be used to find if a node is a parent
int tin[MAX];
int tout[MAX];

void DFS(int node, int parent){
    tin[node] = ++timer;
    p[node][0] = parent;

    //Parents must be filled already, so DP can be done here
    for(int i = 1; i <= log_; i++){
        p[node][i] = p[p[node][i-1]][i-1];
    }

    //DFS
    for(auto ch: connections[node]){
        if(ch != parent){
            DFS(ch, node);
        }
    }
    tout[node] = ++timer;
}

//Is ancestor?
bool upper(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int LCA(int u, int v){
    //u or v is the ancestor
    if(upper(u, v)) return u;
    if(upper(v, u)) return v;
    //Move up the tree till u is just below the LCA
    for(int i = log_; i >= 0; i--){
        if(!upper(p[u][i], v)){
            u = p[u][i];
        }
    }
    //LCA is just above U
    return p[u][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    //Get the log value first
    //Remember that the log value is base 2
    for(log_ = 1; (1 << log_) <= n; log_++);
    log_--;
    DFS(1, 1);

    int m;
    cin >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }

}
