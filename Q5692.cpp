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

    vector<int> facto(10);
    int cur = 1;
    for(int i = 1; i <= 9; i++){
        cur *= i;
        facto[i] = cur;
    }

    while(true){
        string n;
        cin >> n;
        if(n == "0") break;

        int ans = 0;
        int cnt = n.length();
        for(int i = 0; i < n.length(); i++){
            ans += (n[i]-'0') * facto[cnt];
            cnt--;
        }
        cout << ans << "\n";
    }
}
