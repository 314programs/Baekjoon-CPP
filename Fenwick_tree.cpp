#include <bits/stdc++.h>
using namespace std;
#define ll long long 

//Fenwick tree uses binary numbers to add sum of numbers
//The number will hold sum of last 1 on the binary number
//For example: 12 = 1100
//12 holds 100, amount of numbers which is 4

void update(vector<ll> &tree, int i, ll diff){
    while(i < tree.size()){
        tree[i] += diff;
        //Keep adding ones instead of subtracting
        i += (i & -i);
    }
}

ll query(vector<ll> &tree, int i){
    ll ans = 0;
    while(i > 0){
        ans += tree[i];
        //Keep removing ones to get the total sum
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
            //Save this value before change to a[j] is made
            ll diff = k - a[j];
            a[j] = k;
            update(tree, j, diff);
        }
        else{
            //Since fenwick tree can only calculate sums from start to a certain point,
            //Subtract query(tree, k) - query(tree, j-1) to get sum between j-k.
            cout << query(tree, k) - query(tree, j-1) << "\n";
        }
    }

}
