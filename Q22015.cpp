//div. 3 yesterday
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    vector<int> a(3);
    int mx = -1;
    for(int i = 0; i < 3; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int ans = 0;
    for(auto ch: a){
        ans += mx - ch;
    }
    cout << ans;
 
}
