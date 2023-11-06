//2 blogs today

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
        int r, e, c;
        cin >> r >> e >> c;

        if(e - c > r){
            cout << "advertise\n";
        }
        else if(e - c < r){
            cout << "do not advertise\n";
        }
        else{
            cout << "does not matter\n";
        }

    }

}
