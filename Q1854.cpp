#include <bits/stdc++.h>
using namespace std;

struct node{
    int to, cost;
};

vector<node> connections[1001];
//K limit is only till 100, so heaps can be used
priority_queue<int> dist[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int node_cnt, connection_cnt, k;
    cin >> node_cnt >> connection_cnt >> k;

    for(int i = 0; i < connection_cnt; i++){
        int f, t, c;
        cin >> f >> t >> c;
        connections[f].push_back({t, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    dist[1].push(0);
    
    //Dijkstra but instead of finding the shortest, finds all and puts it in max heap
    while(!q.empty()){
        auto current = q.top();
        q.pop();

        for(auto ch: connections[current.second]){
            int next_cost = ch.cost + current.first;
            //If heap is not full or full but next_cost is smaller
            if(dist[ch.to].size() < k || dist[ch.to].top() > next_cost){
                //Since its a max_heap, popping the top means largest value is gone
                if(dist[ch.to].size() == k){
                    dist[ch.to].pop();
                }
                dist[ch.to].push(next_cost);
                q.push(make_pair(next_cost, ch.to));
            }
        }
    }

    for(int i = 1; i <= node_cnt; i++){
        if(dist[i].size() < k){
            cout << "-1\n";
        }
        else{
            cout << dist[i].top() << "\n";
        }
    }

}
