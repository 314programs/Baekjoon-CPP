#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long

bool has(string s, string h){
    for(int i = 0; i < s.length() - h.length()+1; i++){
        if(s.substr(i, h.length()) == h){
            return true;
        }
    }
    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    int tc;
    cin >> tc;

    while(tc--){
        string s;
        cin >> s;

        if(s.length() < 3){
            cout << -1 << "\n";
        }
        else if(has(s, "MOO")){
            cout << s.length() - 3 << "\n";
        }
        else if(has(s, "MOM") || has(s, "OOO")){
            cout << s.length() - 2 << "\n";
        }
        else if(has(s, "OOM")){
            cout << s.length() - 1 << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }

}
