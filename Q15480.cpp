#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
vector<int> connections[MAX];
int p[MAX][20];

//LCA set up
int tin[MAX];
int tout[MAX];
int dist[MAX];

int log_ = 0;
int timer = 0;

//This method of LCA is WAY EASIER
void DFS(int node, int parent){
    tin[node] = ++timer;
    p[node][0] = parent;
    
    //DP, DFS and Distance
    for(int i = 1; i <= log_; i++){
        p[node][i] = p[p[node][i-1]][i-1];
    }

    for(auto to: connections[node]){
        if(to != parent){
            dist[to] = dist[node] + 1;
            DFS(to, node);
        }
    }
    tout[node] = ++timer;
}

bool upper(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int LCA(int u, int v){
    if(upper(u, v)) return u;
    if(upper(v, u)) return v;
    for(int i = log_; i >= 0; i--){
        if(!upper(p[u][i], v)){
            u = p[u][i];
        }
    }
    return p[u][0];
}

//Function for convenience
int calc_dist(int u, int v){
    return dist[u] + dist[v] - (2*dist[LCA(u, v)]);
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
    
    //Set up log value
    for(log_ = 1; (1 << log_) <= n; log_++);
    log_--;
    //Wanted to clarify...
    dist[1] = 0;
    DFS(1, 1);

    int m;
    cin >> m;
    while(m--){
        int r, u, v;
        cin >> r >> u >> v;
        vector<pair<int, int>> t(6);
        //All possibilities
        t[0].second = r;
        t[1].second = u;
        t[2].second = v;
        t[3].second = LCA(u, v);
        t[4].second = LCA(r, u);
        t[5].second = LCA(r, v);

        for(int i = 0; i < 6; i++){
            int x = t[i].second;
            t[i].first = calc_dist(x, u) + calc_dist(x, v) + calc_dist(x, r); 
        }
        //Get the shortest distance for each, that is the answer
        sort(t.begin(), t.end());
        cout << t[0].second << "\n";
    }
}
