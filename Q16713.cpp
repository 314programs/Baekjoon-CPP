#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
     
    //Turn everything into XOR
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    vector<ll> s(n+1);
    s[0] = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        s[i+1] = a[i] ^ s[i];
    }

    ll ans = 0;
    for(int i = 0; i < m; i++){
        ll st, en;
        cin >> st >> en;
        ans ^= (s[en] ^ s[st-1]);
    }
    cout << ans;

}
