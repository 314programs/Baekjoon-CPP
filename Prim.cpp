#include <bits/stdc++.h>
using namespace std;

struct node{
    int to, weight;
    //Opposing symbol since priority queue is always max_heap
    bool operator < (const node & other) const{
        return weight > other.weight;
    }
};

bool visited[10001];
vector<node> connections[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(visited, false, sizeof(visited));
    int node_cnt, connection_cnt;
    cin >> node_cnt >> connection_cnt;
    
    for(int i = 0; i < connection_cnt; i++){
        int a, b, c;
        cin >> a >> b >> c;
        connections[a].push_back({b,c});
        connections[b].push_back({a,c});
    }

    long long ans = 0;
    visited[1] = true;
    priority_queue<node> q;
    
    //Start from 1
    for(node ch: connections[1]){
        q.push(ch);
    }

    while(!q.empty()){
        node current = q.top();
        q.pop();

        if(visited[current.to] == true){
            continue;
        }

        visited[current.to] = true;
        ans += current.weight;

        for(auto ch: connections[current.to]){
            q.push(ch);
        }
    }

    cout << ans;

}
