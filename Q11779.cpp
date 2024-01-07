#include <bits/stdc++.h>
using namespace std;

struct node{
    int to, cost;
};

long long inf = 2147483646;
long long dist[1001];
bool visited[1001];
int parent[1001];
vector<node> connections[1001];
vector<int> ans;

void backtrack(int target){
    if(parent[target] == -1){
        ans.push_back(target);
        return;
    }
    backtrack(parent[target]);
    ans.push_back(target);
}

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
    parent[start] = -1;

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
                parent[ch.to] = current.second;
            }
        }
    }

    cout << dist[end] << "\n";
    backtrack(end);

    cout << ans.size() << "\n";
    for(auto ch: ans){
        cout << ch << " ";
    }

}
