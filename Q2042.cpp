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


//Another way that does not involve recursion...
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

//All initial value is 0
ll tree[3000000];
int b = 1;

void update(int x, ll diff){
    //To get to the leaf node index
    x += b;
    tree[x] += diff;
    while(x > 1){
        //Keep adding to parent node which is at x/2
        tree[x/2] += diff;
        x /= 2;
    }
}

ll sum(int l, int r){
    //Add b to get the leaf node
    l += b;
    r += b;
    ll ans = 0;

    //When at left node, moves to right, start point will be kept
    //When at right node, moves to left, end point will be kept
    //Both meets in the middle
    while(l < r){
        //Even = left child
        if(l%2 == 0){
            l /= 2;
        }
        else{
            //Since its a right child, add it, move to the right and move up
            ans += tree[l];
            l += 1;
            l /= 2;
        }
        
        //Odd = right child
        if(r%2 == 1){
            r /= 2;
        }
        else{
            //Since its a left child, add it, move to the left and move up
            ans += tree[r];
            r -= 1;
            r /= 2;
        }
    }
    if(l == r){
        ans += tree[l];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    m += k;

    //Make the leaf node be a power of 2 because we are making full binary tree
    while(b <= n){
        b *= 2;
    }
    //To get the last index before the leaf node
    b--;

    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        update(i, x);
    }

    while(m--){
        ll i, j, k;
        cin >> i >> j >> k;
        if(i == 1){
            //k-tree[b+j] is the value to add(or subtract)
            update(j, k-tree[b+j]);
        }
        else{
            cout << sum(j, k) << "\n";
        }
    }
    
}

//Another method using fenwick tree
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

void update(vector<ll> &tree, int i, ll diff){
    while(i < tree.size()){
        tree[i] += diff;
        i += (i & -i);
    }
}

ll query(vector<ll> &tree, int i){
    ll ans = 0;
    while(i > 0){
        ans += tree[i];
        i -= (i & -i); 
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n+1);
    vector<ll> tree(n+1, 0);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        update(tree, i, a[i]);
    }

    m += k;

    while(m--){
        ll i, j, k;
        cin >> i >> j >> k;
        if(i == 1){
            ll diff = k - a[j];
            a[j] = k;
            update(tree, j, diff);
        }
        else{
            cout << query(tree, k) - query(tree, j-1) << "\n";
        }
    }

}
