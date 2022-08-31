//First DP+Graph problem that I solved alone!
#include <bits/stdc++.h>
using namespace std;

struct node{
    int to, cost1, cost2;
};

struct cost_val{
    int cost1, cost2;
};

cost_val graph[20][20];
vector<node> connection[20];
long long inf = 100000000;
//Distance for node, W1 and W2
int visited[20][200][200];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int node_cnt;
    cin >> node_cnt;
    
    //Input the graph and make the connections
    for(int y = 0; y < node_cnt; y++){
        string s1;
        cin >> s1;
        for(int x = 0; x < node_cnt; x++){
            if(s1[x] == '.') graph[y][x] = {-1, -1};
            else{
                graph[y][x] = {s1[x]-'0', -1};
            }
        }
    }

    for(int y = 0; y < node_cnt; y++){
        string s2;
        cin >> s2;
        for(int x = 0; x < node_cnt; x++){
            if(s2[x] == '.') continue;
            else{
                graph[y][x].cost2 = s2[x]-'0';
                connection[y].push_back({x, graph[y][x].cost1, graph[y][x].cost2});
            }
        }
    }
    
    //memset don't work on this thing so running a for loop instead
    for(int i = 0; i < 200; i++){
        for(int j = 0; j < 200; j++){
            for(int k = 0; k < node_cnt; k++){
                visited[k][i][j] = inf; 
            }
        }
    }
    

    queue<node> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 0;

    while(!q.empty()){
        node current = q.front();
        q.pop();

        for(auto ch: connection[current.to]){
            int new_cost = (current.cost1 + ch.cost1) * (current.cost2 + ch.cost2);
            //Too big, cannot be answer
            if(current.cost1 + ch.cost1 > 200 || current.cost2 + ch.cost2 > 200) continue;
            //Enter new cost
            if(new_cost < visited[ch.to][current.cost1 + ch.cost1][current.cost2 + ch.cost2]){
                visited[ch.to][current.cost1 + ch.cost1][current.cost2 + ch.cost2] = new_cost;
                q.push({ch.to, current.cost1 + ch.cost1, current.cost2 + ch.cost2});
            }
        }
    }
    
    int ans = inf;
    for(int i = 1; i < 200; i++){
        for(int j = 1; j < 200; j++){
            ans = min(ans, visited[1][i][j]);
        }
    }

    if(ans == inf) cout << -1;
    else cout << ans;



}
