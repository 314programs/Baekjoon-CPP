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

//Code using segment trees, we want to find the node with lowest depth between the range i and j
#include <bits/stdc++.h>
using namespace std;

vector<int> a[100001];
//When was this node firstly visited?
vector<int> first;
//Order of visit
vector<int> dfs_order;
//Depth
vector<int> level;

void init(vector<int> &tree, int node, int start, int end){
    //Use the index since value is unknown
    if(start == end){
        tree[node] = start;
    }
    else{
        init(tree, node*2, start, (start+end)/2);
        init(tree, (node*2)+1, ((start+end)/2)+1, end);
        //Use the depth to find the min
        if(level[tree[node*2]] < level[tree[(node*2)+1]]){
            tree[node] = tree[node*2];
        }
        else{
            tree[node] = tree[(node*2)+1];
        }
    }
}

int query(vector<int> &tree, int node, int start, int end, int i, int j){
    if(start > j || end < i) return -1;
    if(start >= i && end <= j){
        return tree[node];
    }

    int n1 = query(tree, node*2, start, (start+end)/2, i, j);
    int n2 = query(tree, (node*2)+1, ((start+end)/2)+1, end, i, j);

    if(n1 == -1){
        return n2;
    }
    else if(n2 == -1){
        return n1;
    }
    else{
        //Using levels once again
        if(level[n1] < level[n2]){
            return n1;
        }
        else{
            return n2;
        }
    }
}

//Basic DFS
//Length of dfs_order and level are equal
void dfs(int node, int parent, int depth){
    dfs_order.push_back(node);
    level.push_back(depth);
    for(int item : a[node]){
        if(item == parent) continue;
        dfs(item, node, depth+1);
        dfs_order.push_back(node);
        level.push_back(depth);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int f, t;
        cin >> f >> t;
        a[f].push_back(t);
        a[t].push_back(f);
    }
    first.resize(n+1, -1);
    dfs(1, 0, 0);

    //First index for the node to appear
    for(int i = 0; i < dfs_order.size(); i++){
        int node = dfs_order[i];
        if(first[node] == -1){
            first[node] = i;
        }
    }
    
    //this is important as n will be used to aquire the index for dfs_order
    n = dfs_order.size();
    int h = (int) ceil(log2(n));
    int tree_h = (1 << (h+1));
    vector<int> tree(tree_h);
    init(tree, 1, 0, n-1);

    int m;
    cin >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        
        int i = first[u];
        int j = first[v];
        if(i > j) swap(i, j);
        
        //Use index instead of value, get value later using the array
        int lca = query(tree, 1, 0, n-1, i, j);
        cout << dfs_order[lca] << "\n";
    }
    
}
