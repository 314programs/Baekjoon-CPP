#include <bits/stdc++.h>
using namespace std;

int depth[40001];
int parent[40001];
int dist[40001];
struct node{
    int to, cost;
};
vector<node> connections[40001];

//LCA algorithm... easier then expected!
//But this implementation wasn't easy...
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
    
    //Both directions
    for(int i = 0; i < node_cnt-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        connections[a].push_back({b, c});
        connections[b].push_back({a, c});
    }

    memset(depth, -1, sizeof(depth));
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    depth[1] = 0;
    parent[1] = -1;

    //BFS from root, assume its 1
    while(!q.empty()){
        auto current = q.front();
        q.pop();

        for(auto ch: connections[current.first]){
            if(depth[ch.to] != -1) continue;
            depth[ch.to] = depth[current.first] + 1;
            parent[ch.to] = current.first;
            dist[ch.to] = current.second + ch.cost;
            q.push(make_pair(ch.to, dist[ch.to]));
        }
    }

    int tc;
    cin >> tc;

    while(tc--){
        int a, b;
        cin >> a >> b;
        //Quick calculation by getting distance of LCA
        cout << dist[a] + dist[b] - (2*dist[LCA(a, b)]) << "\n";
    }

    
}
