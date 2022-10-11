#include <bits/stdc++.h>
using namespace std;

struct node{
    int from, to, cost;
};

int parent[100000];

bool compare(const node &u, const node &v){
    return u.cost < v.cost;
}

int find_parent(int target){
    if(parent[target] == target) return target;
    parent[target] = find_parent(parent[target]);
    return parent[target];
}

//Kruskal
void union_(int a, int b){
    a = find_parent(a);
    b = find_parent(b);

    if(a > b){
        parent[a] = b;
    }
    else{
        parent[b] = a;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int city_cnt, road_cnt;
    cin >> city_cnt >> road_cnt;
    vector<node> roads(road_cnt);

    for(int i = 0; i < road_cnt; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        roads[i] = {a,b,cost};
    }

    for(int i = 1; i <= city_cnt; i++){
        parent[i] = i;
    }

    int m = 0;
    long long ans = 0;
    sort(roads.begin(), roads.end(), compare);
    
    for(int i = 0; i < road_cnt; i++){
        node ch = roads[i];
        if(find_parent(ch.from) != find_parent(ch.to)){
            union_(ch.from, ch.to);
            ans += ch.cost;
            m = max(m, ch.cost);
        }
    }

    cout << ans - m;


}
