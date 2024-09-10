#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    string s;
    cin >> s;

    int cnt = 0;
    for(auto ch: s){
        if(cnt == 0){
            cout << ch;
            cnt = ch - 'A';
        }
        else{
            cnt--;
        }
    }
 
}
