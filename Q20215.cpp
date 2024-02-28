//Math test tmr...
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    int n, m;
    cin >> n >> m;
    
    cout << fixed << setprecision(7) << (n+m)-sqrt(n*n + m*m);
 
}
