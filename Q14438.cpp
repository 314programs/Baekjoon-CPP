#include <bits/stdc++.h>
using namespace std;

//Segment tree~
void init(vector<int> &tree, vector<int> &a, int node, int start, int end){
    if(start == end){
        tree[node] = a[start];
    }
    else{
        init(tree, a, node*2, start, (start+end)/2);
        init(tree, a, (node*2)+1, ((start+end)/2) + 1, end);
        tree[node] = min(tree[(node*2)+1], tree[node*2]);
    }
}

void update(vector<int> &tree, int change_i, int change_num, int node, int start, int end){
    if(start > change_i || end < change_i) return;
    if(start == end){
        //Update node
        tree[node] = change_num;
        return;
    }
    //Cannot find node to update
    update(tree, change_i, change_num, node*2, start, (start+end)/2);
    update(tree, change_i, change_num, (node*2)+1, ((start+end)/2)+1, end);
    //Update parents
    tree[node] = min(tree[node*2], tree[(node*2)+1]);
}

int query(vector<int> &tree, int node, int start, int end, int i, int j){
    if(start > j || end < i) return -1;
    if(start >= i && end <= j) return tree[node];

    int n1 = query(tree, node*2, start, (start+end)/2, i, j);
    int n2 = query(tree, (node*2)+1, ((start+end)/2)+1, end, i, j);

    if(n1 == -1) return n2;
    else if(n2 == -1) return n1;
    else return min(n1, n2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size);
    init(tree, a, 1, 0, n-1);

    int m;
    cin >> m;
    while(m--){
        int c, i, j;
        cin >> c >> i >> j;
        if(c == 1){
            update(tree, i-1, j, 1, 0, n-1);
        }
        else{
            cout << query(tree, 1, 0, n-1, i-1, j-1) << "\n";
        }
    }
}
