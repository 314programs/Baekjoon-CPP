#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

struct hole{
    int a, b, w;
};
int parent[100001];

int find_parent(int target){
    if(parent[target] == target) return target;
    parent[target] = find_parent(parent[target]);
    return parent[target];
}

void union_member(int a, int b){
    a = find_parent(a);
    b = find_parent(b);

    if(a < b){
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    fstream cin;
    cin.open("wormsort.in");
    ofstream cout;
    cout.open("wormsort.out");
    
    int n, m;
    cin >> n >> m;

    vector<int> cows(n);
    vector<bool> no_need(n+1, true);
    for(int i = 0; i < n; i++){
        cin >> cows[i];
        if(cows[i] != i+1) no_need[i+1] = false;
    }

    vector<hole> worms(m);
    for(int i = 0; i < m; i++){
        cin >> worms[i].a >> worms[i].b >> worms[i].w;
    }
    sort(worms.begin(), worms.end(), [&](hole &u, hole &v){
        return u.w < v.w;
    });

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    int ans = -1;
    int idx = m;
    for(int i = 1; i <= n; i++){
        while(find_parent(i) != find_parent(cows[i-1])){
            idx--;
            union_member(worms[idx].a, worms[idx].b);
        }
    }
    if(idx != m){
        ans = worms[idx].w;
    }
    cout << ans;

    
}
