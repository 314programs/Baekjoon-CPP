#include <bits/stdc++.h>
using namespace std;

int parent[100001];
//DP-ish array, first dimension = node, second dimension 2^i th parent.
int p[100001][20];
int depth[100001];
vector<int> connection[100001];

//LCA using DP
int LCA(int u, int v){
    if(depth[u] < depth[v]){
        swap(u, v);
    }
  
    //Log value for base 2
    int log;
    for(log = 1; (1 << log) <= depth[u]; log++);
    log -= 1;
    
    //We want to reach the value just before or equal to depth of v
    for(int i = log; i >= 0; i--){
        if(depth[u] - (1 << i) >= depth[v]){
            u = p[u][i];
        }
    }

    if(u == v){
        return u;
    }
    else{
        //Move together
        for(int i = log; i >= 0; i--){
            //continue when p[u][i] exists and each parent is different
            //If each parent is the same and we return the value, might not be LCA
            if(p[u][i] != -1 && p[u][i] != p[v][i]){
                u = p[u][i];
                v = p[v][i];
            }
        }
        //Always return parent[u] when doing DP LCA
        return parent[u];
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int node_cnt;
    cin >> node_cnt;

    for(int i = 0; i < node_cnt-1; i++){
        int a,b;
        cin >> a >> b;
        connection[a].push_back(b);
        connection[b].push_back(a);
    }

    memset(parent, -1, sizeof(parent));
    memset(depth, -1, sizeof(depth));
    
    //BFS to find depth
    queue<int> q;
    q.push(1);
    parent[1] = 0;
    depth[1] = 1;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int ch: connection[current]){
            if(depth[ch] != -1) continue;
            depth[ch] = depth[current] + 1;
            parent[ch] = current;
            q.push(ch);
        }
    }
    
    //Setting the first parent
    for(int i = 1; i <= node_cnt; i++){
        p[i][0] = parent[i];
    }
    
    //DP using log base 2...
    for(int j = 1; (1<<j) < node_cnt; j++){
        for(int i = 0; i <= node_cnt; i++){
            //If i's j-1 th parent exists
            if(p[i][j-1] != -1){
                //Using logic of 2^i = 2^i-1 + 2^i-1
                //current node's jth parent is equal to j-1th parent's j-1th parent
                p[i][j] = p[p[i][j-1]][j-1];
            }
        }
    }
    
    //LCA for each case
    int tc;
    cin >> tc;
    while(tc--){
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }

    
}
