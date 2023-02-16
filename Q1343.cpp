//Could have made it simpler... but too lazy
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    string s;
    cin >> s;
    string ans = "";

    int place = 0;
    for(auto ch: s){
        if(ch == 'X'){
            place++;
        }
        else{
            while(place > 0){
                if(place >= 4){
                    ans += "AAAA";
                    place -= 4;
                }
                else if(place >= 2){
                    ans += "BB";
                    place -= 2;
                }
                else{
                    ans = "-1";
                    break;
                }
            }
            place = 0;
            if(ans == "-1") break;
            ans += ".";
        }
    }

    while(place > 0){
        if(place >= 4){
            ans += "AAAA";
            place -= 4;
        }
        else if(place >= 2){
            ans += "BB";
            place -= 2;
        }
        else{
            ans = "-1";
            break;
        }
    }
    cout << ans;



}
