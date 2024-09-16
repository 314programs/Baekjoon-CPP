#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int n;
        char c;
        cin >> n >> c;
        string ans = string(n, c);
        cout << ans << "\n";
    }

}
