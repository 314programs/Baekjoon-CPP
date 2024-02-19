#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int a_cnt = 0, b_cnt = 0;
    string s;
    cin >> s;

    for(auto ch: s){
        if(ch == 'A') a_cnt++;
        else b_cnt++;
    }

    cout << a_cnt << " : " << b_cnt;
 
}
