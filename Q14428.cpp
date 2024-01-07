#include <bits/stdc++.h>
using namespace std;
#define ll long long 
vector<int> a;

void init(vector<int> &tree, int node, int start, int end){
    if(start == end){
        tree[node] = start;
    }
    else{
        init(tree, node*2, start, (start+end)/2);
        init(tree, (node*2)+1, ((start+end)/2)+1, end);

        if(a[tree[node*2]] <= a[tree[(node*2)+1]]){
            tree[node] = tree[node*2];
        }
        else{
            tree[node] = tree[(node*2)+1];
        }
    }
}

void update(vector<int> &tree, int node, int idx, int start, int end){
    if(start > idx || end < idx) return;
    if(start == end){
        //Accidently put val here and sturggled by 1 hours oops
        tree[node] = start;
        return;
    }
    update(tree, node*2, idx, start, (start+end)/2);
    update(tree, (node*2)+1, idx, ((start+end)/2)+1, end);

    if(a[tree[node*2]] <= a[tree[(node*2)+1]]){
        tree[node] = tree[node*2];
    }
    else{
        tree[node] = tree[(node*2)+1];
    }
}

int query(vector<int> &tree, int node, int start, int end, int i, int j){
    if(start > j || end < i) return -1;
    if(start >= i && end <= j){
        return tree[node];
    }
    int n1 = query(tree, node*2, start, (start+end)/2, i, j);
    int n2 = query(tree, (node*2)+1, ((start+end)/2)+1, end, i, j);

    if(n1 == -1) return n2;
    if(n2 == -1) return n1;

    if(a[n1] <= a[n2]){
        return n1;
    }
    else{
        return n2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n;
    cin >> n;
    a.resize(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int h = (int) ceil(log2(n));
    int tree_s = (1 << (h+1));
    vector<int> tree(tree_s);
    init(tree, 1, 0, n-1);

    int m;
    cin >> m;
    while(m--){
        int c, i, j;
        cin >> c >> i >> j;
        if(c == 1){
            a[i-1] = j;
            update(tree, 1, i-1, 0, n-1);
        }
        else{
            cout << query(tree, 1, 0, n-1, i-1, j-1) + 1 << "\n";
        }
    }
}
