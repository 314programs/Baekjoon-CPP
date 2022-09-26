#include <bits/stdc++.h>
using namespace std;

struct item{
    int l, s;
};

//Free lesson in school yay
//I love segment trees
void init(vector<item> &tree, vector<int> &a, int node, int start, int end){
    if(start == end){
        tree[node].s = a[start];
        tree[node].l = a[start];
    }
    else{
        init(tree, a, node*2, start, (start+end)/2);
        init(tree, a, (node*2)+1, ((start+end)/2)+1, end);
        tree[node].s = min(tree[node*2].s, tree[(node*2)+1].s);
        tree[node].l = max(tree[node*2].l, tree[(node*2)+1].l);
    }
}

item query(vector<item> &tree, int node, int start, int end, int i, int j){
    if(start > j || end < i) return (item){-1, -1};
    if(start >= i && end <= j){
        return tree[node];
    }

    item n1 = query(tree, node*2, start, (start+end)/2, i, j);
    item n2 = query(tree, (node*2) + 1, ((start+end)/2)+1, end, i, j);
    if(n1.l == -1) return n2;
    if(n2.l == -1) return n1;
    else{
        return (item){max(n1.l, n2.l), min(n1.s, n2.s)};
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int h = (int) ceil(log2(n));
    int tree_h = (1 << (h+1));
    vector<item> tree(tree_h);
    init(tree, a, 1, 0, n-1);

    while(m--){
        int i, j;
        cin >> i >> j;
        item ans = query(tree, 1, 0, n-1, i-1, j-1);
        cout << ans.s << " " << ans.l << "\n";
    }

}
