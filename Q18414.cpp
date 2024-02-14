#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);
 
    int x, l, r;
    cin >> x >> l >> r;

    if(x >= l && x <= r){
        cout << x;
    }
    else if(x >= r){
        cout << r;
    }
    else{
        cout << l;
    }
    
}
