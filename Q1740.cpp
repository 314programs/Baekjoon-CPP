//Pow gets so inaccurate I cannot man

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll unsigned long long


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    ll n;
    cin >> n;

    ll ans = 0;
    ll cnt = 0;

    string s;

    while(n != 0){
        s += '0' + (n%2);
        n /= 2;
    }

    ll track = 1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1') ans += track;
        track *= 3;
    }

    cout << ans;
 
}
 

 
