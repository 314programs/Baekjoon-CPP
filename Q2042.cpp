#include <bits/stdc++.h>
using namespace std;

//Always use long long even though it makes the code look messy
void init(vector<long long> &tree, vector<long long> &a, int node, int start, int end){
    if(start == end){
        tree[node] = a[start]; 
    }
    else{
        init(tree, a, node*2, start, (start+end)/2);
        init(tree, a, (node*2)+1, ((start+end)/2)+1, end);
        //Instead of min(), use addition
        tree[node] = tree[node*2] + tree[(node*2)+1];
    }
}

void update(vector<long long> &tree, int node, int idx, long long val, int start, int end){
    if(start > idx || end < idx) return;
    if(start == end){
        tree[node] = val;
        return;
    }

    update(tree, node*2, idx, val, start, (start+end)/2);
    update(tree, (node*2)+1, idx, val, ((start+end)/2)+1, end);
    tree[node] = tree[node*2] + tree[(node*2)+1];
}

long long query(vector<long long> &tree, int node, int start, int end, int i, int j){
    if(start > j || end < i) return -1;
    if(start >= i && end <= j) return tree[node];

    long long n1 = query(tree, node*2, start, (start+end)/2, i, j);
    long long n2 = query(tree, (node*2)+1, ((start+end)/2)+1, end, i, j);

    if(n1 == -1) return n2;
    else if(n2 == -1) return n1;
    else return n1 + n2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int h = (int) ceil(log2(n));
    int tree_h = (1 << (h+1));
    vector<long long> tree(tree_h);
    init(tree, a, 1, 0, n-1);

    m += k;
    while(m--){
        long long c, i, j;
        cin >> c >> i >> j;

        if(c == 1){
            update(tree, 1, i-1, j, 0, n-1);
        }
        else{
            cout << query(tree, 1, 0, n-1, i-1, j-1) << "\n";
        }
    }
}
