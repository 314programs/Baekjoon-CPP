#include <bits/stdc++.h>
using namespace std;
#define ll long long 

//Repeated fenwick tree, 2D fenwick tree
void update(vector<vector<ll>> &tree, int x, int y, int val){
    for(int i = x; i <= tree.size(); i += (i & -i)){
        for(int j = y; j <= tree.size(); j += (j & -j)){
            tree[i][j] += val;
        }
    }
}

ll query(vector<vector<ll>> &tree, int x, int y){
    ll ans = 0;
    for(int i = x; i > 0; i -= (i & -i)){
        for(int j = y; j > 0; j -= (j & -j)){
            ans += tree[i][j];
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> a(n+1, vector<ll>(n+1));
    vector<vector<ll>> tree(n+1, vector<ll>(n+1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            update(tree, i, j, a[i][j]);
        }
    }

    while(m--){
        int c;
        cin >> c;

        if(c == 0){
            ll i, j, v;
            cin >> i >> j >> v;

            ll diff = v-a[i][j];
            a[i][j] = v;
            update(tree, i, j, diff);
        }
        else{
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            //Substract the overwrapping parts
            cout << query(tree, x2, y2) - query(tree, x2, y1-1) - query(tree, x1-1, y2) + query(tree, x1-1, y1-1) << "\n";
        }

    }

}
