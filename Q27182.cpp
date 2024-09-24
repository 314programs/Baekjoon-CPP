#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#define int long long

void setIO(string s = ""){
	if(s == "") return;
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}


int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    if(a > b){
        cout << b + 7;
    }
    else{
        int numday = (14 - a) + b;
        int ans = (b+7);
        if(ans > numday){
            ans %= numday;
        }
        cout << ans;
    }

}
