#include <bits/stdc++.h>
using namespace std;

long long const mod = 1000000007;

//Segment tree my beloved
void init(vector<long long> &tree, vector<long long> &a, int node, int start, int end){
    if(start == end){
        tree[node] = a[start];
    }
    else{
        init(tree, a, node*2, start, (start+end)/2);
        init(tree, a, (node*2)+1, ((start+end)/2)+1, end);
        tree[node] = (tree[node*2] * tree[(node*2)+1])%mod;
    }
}

void update(vector<long long> &tree, int idx, long long val, int node, int start, int end){
    if(start > idx || end < idx) return;
    if(start == end){
        tree[node] = val;
        return;
    }
    update(tree, idx, val, node*2, start, (start+end)/2);
    update(tree, idx, val, (node*2)+1, ((start+end)/2)+1, end);
    tree[node] = (tree[node*2] * tree[(node*2)+1])%mod;
}

long long query(vector<long long> &tree, int node, int start, int end, int i, int j){
    if(start > j || end < i) return 1;
    if(start >= i && end <= j){
        return tree[node];
    }
    long long n1 = query(tree, node*2, start, (start+end)/2, i, j);
    long long n2 = query(tree, (node*2)+1, ((start+end)/2)+1, end, i, j);

    return (n1*n2)%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    m += k;

    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    
    int h = (int)ceil(log2(n));
    //Struggled for solid 20 minutes cause I accidently put n instead of h...
    //Going blind
    long long tree_size = (1 << (h+1));
    vector<long long> tree(tree_size);
    init(tree, a, 1, 0, n-1);

    while(m--){
        long long a, i, j;
        cin >> a >> i >> j;
        if(a == 1){
            update(tree, i-1, j, 1, 0, n-1);
        }
        else{
            cout << query(tree, 1, 0, n-1, i-1, j-1) << "\n";
        }
    }
}
