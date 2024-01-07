//Bellman ford allows negatives unlike other shortest path finding algorithms
#include <bits/stdc++.h>
using namespace std;

long long inf = 2147483646;
long long dist[501];

struct node{
    int from, to, cost;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int node_cnt, connection_cnt;
    cin >> node_cnt >> connection_cnt;

    vector<node> connections(connection_cnt);
    for(int i = 0; i < connection_cnt; i++){
        int f, t, c;
        cin >> f >> t >> c;
        connections[i] = {f, t, c};
    }

    for(int i = 2; i <= node_cnt; i++){
        dist[i] = inf;
    }
    dist[1] = 0;
    bool loop_ = false;

    for(int i = 1; i <= node_cnt; i++){
        for(int j = 0; j < connection_cnt; j++){
            int f = connections[j].from;
            int t = connections[j].to;
            int c = connections[j].cost;
            if(dist[f] != inf && dist[f] + c < dist[t]){
                dist[t] = dist[f] + c;
                //Cost shouldn't change here since maximum connection between nodes is n-1...
                //This means that a negative cycle exists
                if(i == node_cnt){
                    loop_ = true;
                }
            }
        }
    }

    if(loop_){
        cout << -1;
    }
    else{
        for(int i = 2; i <= node_cnt; i++){
            if(dist[i] == inf) cout << -1 << "\n";
            else cout << dist[i] << "\n";
        }
    }

}
