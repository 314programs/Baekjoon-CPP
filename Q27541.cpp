//Busy because I have to train students today

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    int n;
    cin >> n;

    string s;
    cin >> s;

    if(s.back() == 'G'){
        cout << s.substr(0, s.size()-1);
    }
    else{
        cout << s << "G";
    }

}
