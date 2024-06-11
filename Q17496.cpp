//Is this... a stardew valley reference???

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, t, c, p;
    cin >> n >> t >> c >> p;

    cout << ((n-1)/t) * (c*p);

}
