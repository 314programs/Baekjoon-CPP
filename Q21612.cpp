#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int b;
    cin >> b;
    b = (5*b) - 400;

    cout << b << "\n";
    if(b == 100){
        cout << 0;
    }
    else if(b > 100){
        cout << -1;
    }
    else{
        cout << 1;
    }


}
