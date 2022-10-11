#include <bits/stdc++.h>
using namespace std;

void modify(vector<long long> &tree, int val, int idx, int start, int end, int node){
    if(start > idx || end < idx) return;
    if(start == end){
        tree[node] = val;
        return;
    }
    
    modify(tree, val, idx, start, (start+end)/2, node*2);
    modify(tree, val, idx, ((start+end)/2)+1, end, (node*2)+1);
    tree[node] = tree[node*2] + tree[(node*2)+1];
}

long long sum(vector<long long> &tree, int node, int start, int end, int i, int j){
    if(end < i || start > j) return 0;
    if(start >= i && end <= j){
        return tree[node];
    }
    long long n1 = sum(tree, node*2, start, (start+end)/2, i, j);
    long long n2 = sum(tree, (node*2)+1, ((start+end)/2)+1, end, i, j);
    return n1+n2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int h = (int) ceil(log2(n));
    int tree_s = (1 << (h+1));
    //No need to use init function as all sums will be zero... convinient!
    vector<long long> tree(tree_s, 0);

    while(m--){
        int s, i, j;
        cin >> s >> i >> j;
        if(s == 1){
            modify(tree, j, i-1, 0, n-1, 1);
        }
        else{
            if(i > j) swap(i, j);
            cout << sum(tree, 1, 0, n-1, i-1, j-1) << "\n";
        }
    }
    
}
