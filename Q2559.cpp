//Prefix sums

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> s(n+1);
    s[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s[i+1] = s[i] + a[i];
    }

    int ans = -1e9;
    for(int i = 0; i <= n - k; i++){
        ans = max(ans, s[i+k]-s[i]);
    }
    cout << ans;

}
