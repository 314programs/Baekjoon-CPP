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
 
    while(tc--){
        int n;
        cin >> n;

        int cnt = 0;
        while(n){
            if(n%2 == 1) cout << cnt << " ";
            n /= 2;
            cnt++;
        }
        cout << "\n";
 
    }
 
}
