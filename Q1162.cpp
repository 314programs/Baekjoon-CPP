#include <bits/stdc++.h>
using namespace std;

struct node{
    int to, cost;
};

vector<node> connections[10001];
long long dist[10001][21];
//Thank you to the person who gave me this inf
long long inf = 9223372036854775800;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int node_cnt, connection_cnt, clean_cnt;
    cin >> node_cnt >> connection_cnt >> clean_cnt;
    
    for(int i = 0; i < connection_cnt; i++){
        int f, t, c;
        cin >> f >> t >> c;
        connections[f].push_back({t, c});
        connections[t].push_back({f, c});
    }

    for(int i = 1; i <= node_cnt; i++){
        for(int j = 0; j <= clean_cnt; j++){
            dist[i][j] = inf;
        }
    }

    dist[1][clean_cnt] = 0;

    priority_queue<tuple<long long, long long, long long>, vector<tuple<long long, long long, long long>>, greater<tuple<long long, long long, long long>>> q;
    q.push(make_tuple(0, 1, clean_cnt));

    while(!q.empty()){
        tuple<long long, long long, long long> current = q.top();
        q.pop();

        long long current_dist = get<0> (current);
        long long current_node = get<1> (current);
        long long current_k = get<2> (current);

        if(dist[current_node][current_k] < current_dist){
            continue;
        }
        
        //Solving it in a 2 dimensional DP + Dijkstra
        for(auto ch: connections[current_node]){
            if(current_k > 0 && dist[ch.to][current_k-1] > dist[current_node][current_k]){
                dist[ch.to][current_k-1] = dist[current_node][current_k];
                q.push(make_tuple(dist[ch.to][current_k-1], ch.to, current_k-1));
            }
            if(dist[ch.to][current_k] > dist[current_node][current_k] + ch.cost){
                dist[ch.to][current_k] = dist[current_node][current_k] + ch.cost;
                q.push(make_tuple(dist[ch.to][current_k], ch.to, current_k));
            }
        }

    }

    long long ans = inf;
    for(int i = 0; i <= clean_cnt; i++){
        ans = min(dist[node_cnt][i], ans);
    }
    cout << ans;

}
