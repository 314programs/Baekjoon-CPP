//I forgot how to dijkstra
#include <bits/stdc++.h>
using namespace std;

struct node{
    int to, cost;
};

long long inf = 2147483646;
long long dist[1001];
bool visited[1001];
vector<node> connections[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int node_cnt, connection_cnt;
    cin >> node_cnt >> connection_cnt;

    for(int i = 0; i < connection_cnt; i++){
        int f, t, c;
        cin >> f >> t >> c;
        connections[f].push_back({t, c});
    }  

    int start, end;
    cin >> start >> end;

    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= node_cnt; i++){
        dist[i] = inf;
    }

    dist[start] = 0;
    
    //Min_heap to get minimum distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, start));

    while(!q.empty()){
        auto current = q.top();
        q.pop();

        if(visited[current.second]){
            continue;
        }
        visited[current.second] = true;

        for(auto ch: connections[current.second]){
            if(dist[ch.to] > current.first + ch.cost){
                dist[ch.to] = current.first + ch.cost;
                q.push(make_pair(dist[ch.to], ch.to));
            }
        }
    }

    cout << dist[end];


}
