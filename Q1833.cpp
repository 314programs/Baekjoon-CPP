#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int parent[201];

struct road{
    int a, b, cost;
};

bool compare(road &u, road &v){
    return u.cost < v.cost;
}

int find_parent(int target){
    if(target == parent[target]) return target;
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    int matrix[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    vector<road> r;
    int cost = 0;
    //Roads that are already placed must be counted and put into union
    //Count from i+1 for j as some elements are repeated
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(matrix[i][j] < 0){
                cost += abs(matrix[i][j]);
                union_(i+1, j+1);
            }
            else{
                r.push_back((road){i+1, j+1, abs(matrix[i][j])});
            }
        }
    }
    
    //Kruskal my beloved
    sort(r.begin(), r.end(), compare);
    vector <pair<int, int> > ans;

    for(auto ch: r){
        if(find_parent(ch.a) != find_parent(ch.b)){
            union_(ch.a, ch.b);
            ans.push_back(make_pair(ch.a, ch.b));
            cost += ch.cost;
        }
    }
    cout << cost << " " << ans.size() << "\n";
    for(auto ch: ans){
        cout << ch.first << " " << ch.second << "\n";
    }

}
