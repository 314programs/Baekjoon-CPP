
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
       int a, b;
       cin >> a >> b;
       cout << a << " ";
       int s1 = 0;
       for(int i = 1; i <= b; i++){
           s1 += i;
       }
       int s2 = 0;
       for(int i = 1; i <= b; i++){
           s2 += i*2;
       }
       int s3 = 1;
       for(int i = 1; i <= b-1; i++){
           s3 += i*2 + 1;
       }
       cout << s1 << " " << s3 << " " << s2 << "\n";
   }
}
