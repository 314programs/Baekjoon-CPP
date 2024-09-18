#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
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


   int tc;
   cin >> tc;
   while(tc--){
       int n;
       cin >> n;
       int cur = 0;
       int ans = 0;
       for(int i = 0; i < n; i++){
           int a, b;
           cin >> a >> b;
           cur += a - b;
           if(cur < ans) ans = cur;
       }
       cout << abs(ans) << "\n";
   }


}
