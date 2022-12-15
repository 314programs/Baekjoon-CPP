//Quick union find
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

//Union find
int parent[201];
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
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int city, connection;
    cin >> city >> connection;

    for(int i = 0; i < city; i++){
        parent[i] = i;
    }

    int nodes[city+1][city+1];
    for(int i = 0; i < city; i++){
        for(int j = 0; j < city; j++){
            cin >> nodes[i][j];
        }
    }
    
    //Mark all unions...
    //I think I can make this more efficient as points are repeated but...
    //Its still quick enough
    for(int i = 0; i < city; i++){
        for(int j = 0; j < city; j++){
            if(nodes[i][j] == 1){
                union_(i, j);
            }
        }
    }

    vector<int> a(connection);
    for(int i = 0; i < connection; i++){
        cin >> a[i];
    }

    string ans = "YES";
    //If all travelling points are connected
    for(int i = 0; i < connection-1; i++){
        if(find_parent(a[i]-1) != find_parent(a[i+1]-1)){
            ans = "NO";
        }
    }
    cout << ans;


}
