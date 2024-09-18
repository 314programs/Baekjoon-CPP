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


   string s;
   cin >> s;
   int cnt = 0;
   while(s.length() > 1){
       cnt++;
       int n = 1;
       for(auto ch: s){
           n *= ch - '0';
       }
       s = to_string(n);
   }
   cout << cnt;
}
