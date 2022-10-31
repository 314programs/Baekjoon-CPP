#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

vector<int> tree[1 << 18];

//Very similar to segment trees but using vectors instead
void init(vector<int> &a, int node, int start, int end){
    if(start == end){
        tree[node].push_back(a[start]);
        return;
    }
    
    //Split into 2 and then merge them together after, just like a merge sort
    int mid = (start+end)/2;
    init(a, node*2, start, mid);
    init(a, (node*2)+1, mid+1, end);

    tree[node].resize(end-start+1);
    merge(all(tree[node*2]), all(tree[(node*2) + 1]), tree[node].begin());

}

int query(int node, int i, int j, int start, int end, int k){
    //Out of range
    if(start > j || end < i) return 0;
    //How many elements are bigger then k?
    if(start >= i && end <= j){
        return tree[node].end() - upper_bound(all(tree[node]), k);
    }

    //Split into 2 and merge
    int mid = (start+end)/2;
    int t1 = query(node*2, i, j, start, mid, k);
    int t2 = query((node*2) + 1, i, j, mid+1, end, k);
    return t1+t2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    //Initialise the tree
    init(a, 1, 0, n-1);

    int m;
    cin >> m;

    //Take in query
    while(m--){
        int i, j, k;
        cin >> i >> j >> k;
        cout <<  query(1, i-1, j-1, 0, n-1, k) << "\n";
    }

}
