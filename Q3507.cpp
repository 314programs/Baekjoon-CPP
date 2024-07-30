//Working on Div. 3 now

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n;
    cin >> n;

    if(n > 198){
        cout << 0;
    }
    else{
        int ans = 0;
        for(int i = 0; i <= 99; i++){
            if(i <= 99 && (n-i) <= 99 && (n-i) >= 0){
                ans++;
            }
        }
        cout << ans;
    }

}
