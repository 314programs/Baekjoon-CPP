#include <bits/stdc++.h>
using namespace std;

int dp[100001][20];
struct node{
    int to, cost;
};
vector<node> connection[100001];
int parents[100001];
int depth[100001];
int len[100001];
//Instead of dist, we calculate len which is the min or max len
int len_min[100001][20];
int len_max[100001][20];

//LCA using Dp to make it faster
pair<int, int> LCA(int u, int v){
    if(depth[u] < depth[v]){
        swap(u, v);
    }
    int ans_min = 10000000;
    int ans_max = 0;

    int log = 1;
    for(log = 1; (1 << log) <= depth[u]; log++);
    log -= 1;

    for(int i = log; i >= 0; i--){
        if(depth[u] - (1 << i) >= depth[v]){
            //Get min and max road
            ans_min = min(len_min[u][i], ans_min);
            ans_max = max(len_max[u][i], ans_max);
            u = dp[u][i];
        }
    }

    if(u == v){
        return make_pair(ans_min, ans_max);
    }
    else{
        for(int i = log; i >= 0; i--){
            if(dp[u][i] != -1 && dp[u][i] != dp[v][i]){
                //Get min and max road
                ans_min = min(len_min[u][i], ans_min);
                ans_max = max(len_max[u][i], ans_max);
                ans_min = min(len_min[v][i], ans_min);
                ans_max = max(len_max[v][i], ans_max);
                u = dp[u][i];
                v = dp[v][i];
            }
        }
        //Get min and max road...again...
        ans_min = min(len_min[u][0], ans_min);
        ans_max = max(len_max[u][0], ans_max);
        ans_min = min(len_min[v][0], ans_min);
        ans_max = max(len_max[v][0], ans_max);
        return make_pair(ans_min, ans_max);
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int node_cnt;
    cin >> node_cnt;
    
    for(int i = 0; i < node_cnt-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        connection[a].push_back({b,c});
        connection[b].push_back({a,c});
    }

    memset(depth, -1, sizeof(depth));

    queue<int> q;
    q.push(1);
    depth[1] = 0;
    parents[1] = 0;
    
    //BFS to find depth
    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(auto ch: connection[current]){
            if(depth[ch.to] != -1) continue;
            depth[ch.to] = depth[current] + 1;
            parents[ch.to] = current;
            len[ch.to] = ch.cost;
            q.push(ch.to);
        }
    }

    for(int i = 1; i <= node_cnt; i++){
        dp[i][0] = parents[i];
        len_min[i][0] = len[i];
        len_max[i][0] = len[i];
    }
    
    //DP procedure with finding the min and max road
    for(int j = 1; (1 << j) < node_cnt; j++){
        for(int i = 1; i <= node_cnt; i++){
            if(dp[i][j-1] == -1) continue;
            dp[i][j] = dp[dp[i][j-1]][j-1];
            len_min[i][j] = len_min[i][j-1];
            len_max[i][j] = len_max[i][j-1];

            if(dp[dp[i][j-1]][j-1] != -1){
                len_min[i][j] = min(len_min[i][j-1], len_min[dp[i][j-1]][j-1]);
                len_max[i][j] = max(len_max[i][j-1], len_max[dp[i][j-1]][j-1]);
            }
        }
    }

    int tc;
    cin >> tc;
    while(tc--){
        int a, b;
        cin >> a >> b;
        auto l = LCA(a, b);
        cout << l.first << " " <<l.second<< "\n";
    }
    
}
