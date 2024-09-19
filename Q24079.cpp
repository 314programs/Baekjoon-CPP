#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    int x,y,z;
    cin >> x >> y >> z;

    if(x+y > z){
        cout << 0;
    }
    else{
        cout << 1;
    }
 
}
