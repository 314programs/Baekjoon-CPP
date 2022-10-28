#include <bits/stdc++.h>
using namespace std;

//Learned merge sort tree just for this
//Had to look up solutions though, turns out its binary search

#define all(v) v.begin(), v.end()
vector<int> tree[400000];
vector<int> a;

//Merge sort tree
void init(int node, int start, int end){
    if(start == end){
        tree[node].push_back(a[start]);
        return;
    }

    int mid = (start+end)/2;
    init(node*2, start, mid);
    init((node*2)+1, mid+1, end);

    tree[node].resize(end-start+1);
    merge(all(tree[node*2]), all(tree[(node*2)+1]), tree[node].begin());

}

int query(int node, int i, int j, int start, int end, int k){
    if(start > j || end < i) return 0;
    if(start >= i && end <= j){
        //How many elements are smaller then k?
        //Upper bound returns iterator pointing towards the first element that has greater then current value
        return upper_bound(all(tree[node]), k) - tree[node].begin();
    }

    int mid = (start+end)/2;
    int t1 = query(node*2, i, j, start, mid, k);
    int t2 = query((node*2)+1, i, j, mid+1, end, k);
    return t1+t2;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    init(1, 0, n-1);
    
    
    for(int i = 0; i < m; i++){
        int s, e, k;
        cin >> s >> e >> k;

        int ans = 0;
        int l = -1e9; int r = 1e9;
        //Binary search to find suitable k
        while(l <= r){
            int mid = (l+r)/2;
            int t = query(1, s-1, e-1, 0, n-1, mid);

            if(t < k){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        //We want the l value because upper bound returns iterator pointing towards the first element that has greater then current value
        //This means that the lowest value possible would be the value inside the list
        cout << l << "\n";
    }

}
