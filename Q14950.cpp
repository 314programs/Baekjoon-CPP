#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int parent[10001];
struct road{
    int f, t, c;
};

bool compare(const road &u, const road &v){
    return u.c < v.c;
}

int find_parent(int target){
    if(parent[target] != target){
        parent[target] = find_parent(parent[target]);
        return parent[target];
    }
    return target;
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<road> a;
    for(int i = 0; i < m; i++){
        int f, t, c;
        cin >> f >> t >> c;
        a.push_back({f, t, c});
        a.push_back({t, f, c});
    }
    sort(a.begin(), a.end(), compare);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    int ans = 0;
    int add_on = 0;

    for(auto ch: a){
        if(find_parent(ch.f) != find_parent(ch.t)){
            union_(ch.f, ch.t);
            ans += ch.c + add_on;
            add_on += k;
        }
    }

    cout << ans;

}
