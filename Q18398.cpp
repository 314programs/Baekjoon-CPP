//Chinese test tomorrow ah

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

    while(tc--){
        int n;
        cin >> n;

        while(n--){
            int a, b;
            cin >> a >> b;
            cout << a+b << " " << a*b << "\n";
        }

    }
 
}
