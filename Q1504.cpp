#include <bits/stdc++.h>
using namespace std;

struct node{
    int to, cost;
};

int node_cnt, connection_cnt;
vector<node> connections[801];
int dist[801];
bool check[801];
//Inf value = ((max node count + max cost) * 2) + 1 for worst case scenario
long long inf = 1600001;

long long dijkstra(int start, int end){
    memset(check, false, sizeof(check));
    for(int i = 1; i <= node_cnt; i++){
        dist[i] = inf;
    }
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, start));

    while(!q.empty()){
        auto current = q.top();
        q.pop();

        if(check[current.second]){
            continue;
        }
        check[current.second] = true;

        for(auto ch: connections[current.second]){
            if(dist[ch.to] > dist[current.second] + ch.cost){
                dist[ch.to] = dist[current.second] + ch.cost;
                q.push({dist[ch.to], ch.to});
            }
        }
    }

    return dist[end];

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> node_cnt >> connection_cnt;

    for(int i = 0; i < connection_cnt; i++){
        int f, t, c;
        cin >> f >> t >> c;
        connections[f].push_back({t, c});
        connections[t].push_back({f, c});
    }

    int in_1, in_2;
    cin >> in_1 >> in_2;
    
    //Find smallest out of 2 possible methods
    long long temp1 = dijkstra(1, in_1) + dijkstra(in_1, in_2) + dijkstra(in_2, node_cnt);
    long long temp2 = dijkstra(1, in_2) + dijkstra(in_2, in_1) + dijkstra(in_1, node_cnt);

    long long ans = min(temp1, temp2);
    if(ans >= inf){
        cout << "-1";
    }
    else{
        cout << ans;
    }

}
