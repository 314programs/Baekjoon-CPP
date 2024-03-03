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

    vector<int> a(n);
    int s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }

    for(auto ch: a){
        cout << m*((float)ch/s) << "\n";
    }

}
