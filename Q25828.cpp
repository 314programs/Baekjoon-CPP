#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    int ind = a*b;
    int group = a + b*c;

    if(ind > group){
        cout << 2;
    }
    else if(ind < group){
        cout << 1;
    }
    else{
        cout << 0;
    }

}
