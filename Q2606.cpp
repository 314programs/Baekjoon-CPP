//Use unions to solve this problem
#include <bits/stdc++.h>
using namespace std;

int parent[101];

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
    
    int c_num;
    cin >> c_num;

    int connection_num;
    cin >> connection_num;

    for(int i = 0; i <= c_num; i++){
        parent[i] = i;
    }

    for(int i = 0; i < connection_num; i++){
        int a, b;
        cin >> a >> b;
        union_member(a, b);
    }

    int ans = 0;
    for(int i = 0; i <= c_num; i++){
        if(find_parent(i) == 1){
            ans++;
        }
    }
    cout << ans-1;
}
