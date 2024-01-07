#include <bits/stdc++.h>
using namespace std;

int parent[10001];

struct node{
    int weight, a, b;
};

bool compare(const node &u, const node &v){
    return u.weight < v.weight;
}

int find_parent(int target){
    if(parent[target] == target) return target;
    parent[target] = find_parent(parent[target]);
    return parent[target];
}

void union_(int a, int b){
    a = find_parent(a);
    b = find_parent(b);

    if(a < b){
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int node_cnt, connection_cnt;
    cin >> node_cnt >> connection_cnt;
    
    vector<node> connections(connection_cnt);

    for(int i = 1; i <= node_cnt; i++){
        parent[i] = i;
    }

    for(int i = 0; i < connection_cnt; i++){
        int a, b, c;
        cin >> a >> b >> c;
        connections[i] = {c,a,b};
    }

    sort(connections.begin(), connections.end(), compare);
    int ans = 0;
    for(int i = 0; i < connection_cnt; i++){
        node current = connections[i];
        if(find_parent(current.a) != find_parent(current.b)){
            union_(current.a, current.b);
            ans += current.weight;
        }
    }

    cout << ans;

}
