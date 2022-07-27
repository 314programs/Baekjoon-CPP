//Been so long since I did union find
#include <bits/stdc++.h>
using namespace std;

int parent[1000001];

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

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }


    for(int i = 0; i < m; i++){
        int check, a, b;
        cin >> check >> a >> b;
        if(check == 1){ 
            if(find_parent(a) != find_parent(b)){
                cout << "NO" << "\n";
            }
            else{
                cout << "YES" << "\n";
            }
        }
        else{
            union_member(a, b);
        }
    }
   
}
