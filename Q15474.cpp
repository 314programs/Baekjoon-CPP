//GREEN!

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    float n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    int x = ceil(n/a)*b;
    int y = ceil(n/c)*d;
    cout << min(x, y);
 
}
