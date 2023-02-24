//Dinner outside today

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    int tc;
    cin >> tc;
 
    while(tc--){
        int n;
        cin >> n;

        if(n%2 == 0) cout << n << " is even\n";
        else cout << n << " is odd\n";

    }
 
}
