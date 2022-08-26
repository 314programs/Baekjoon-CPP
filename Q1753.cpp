#include <bits/stdc++.h>
using namespace std;

struct Node{
    int to, cost;
};

long long inf = 2147483647;
vector<Node> connections[20001];
bool visited[20001];
int dist[20001];

int node_cnt, connections_cnt, start;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> node_cnt >> connections_cnt;
    cin >> start;

    for(int i = 0; i < connections_cnt; i++){
        int f, t, c;
        cin >> f >> t >> c;
        connections[f].push_back({t, c});
    }

    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= node_cnt; i++){
        dist[i] = inf;
    }
    
    //Min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, start});
    dist[start] = 0;
    
    //Dijkstra that i forgor :skull:
    while(!q.empty()){
        auto current = q.top();
        q.pop();

        if(visited[current.second]){
            continue;
        }
        visited[current.second] = true;

        for(auto ch: connections[current.second]){
            int &current_dist = dist[ch.to];
            if(current_dist > current.first + ch.cost){
                current_dist = current.first + ch.cost;
                q.push({current_dist, ch.to});
            }
        }
    }

    for(int i = 1; i <= node_cnt; i++){
        int temp = dist[i];
        if(temp == inf) cout << "INF\n";
        else cout << temp << "\n";
    }

}
