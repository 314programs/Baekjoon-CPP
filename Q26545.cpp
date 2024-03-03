//Got a cold
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long

 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int tc;
    cin >> tc;

    int ans = 0;

    while(tc--){
        int num;
        cin >> num;
        ans += num;
    }
    cout << ans;

}
