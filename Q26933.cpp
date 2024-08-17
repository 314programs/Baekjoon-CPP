#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int tc;
    cin >> tc;
    int ans = 0;

    while(tc--){
        int a, b, c;
        cin >> a >> b >> c;

        if(b > a){
            ans += c*(b-a);
        }
    }
    cout << ans;

}
