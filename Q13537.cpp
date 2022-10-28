//Learned about merge sort trees cause I felt like learning it today
#include <bits/stdc++.h>
using namespace std;

//Very convinient
#define all(v) v.begin(), v.end()

vector<int> tree[400000];
int n;
vector<int> a;

//Similar to segment tree initialization, but with sorted lists
void ini(int node, int start, int end){
    if(start == end){
        tree[node].push_back(a[start]);
        return;
    }

    int mid = (start+end)/2;
    ini(node*2, start, mid);
    ini((node*2)+1, mid+1, end);
    
    tree[node].resize(end-start+1);
    //Merge 2 lists into 1, its just like merge sort
    merge(all(tree[node*2]), all(tree[(node*2)+1]), tree[node].begin());

}

int query(int node, int i, int j, int start, int end, int search){
    //Out of range?
    if(start > j || end < i) return 0;
    //Returns elements bigger then search
    if(start >= i && end <= j){
        return tree[node].end() - upper_bound(all(tree[node]), search);
    }

    int mid = (start+end)/2;
    int t1 = query(node*2, i, j, start, mid, search);
    int t2 = query((node*2)+1, i, j, mid+1, end, search);
    return t1+t2;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ini(1, 0, n-1);

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int s, e, k;
        cin >> s >> e >> k;
        cout << query(1, s-1, e-1, 0, n-1, k) << "\n";
    }

}
