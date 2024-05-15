//Math test gone... but SAT left?
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    string s;
    getline(cin, s);

    if((s[0]-'0') + (s[4]-'0') == (s[8]-'0')){
        cout << "YES";
    }
    else{
        cout << "NO\n";
    }
 
}
