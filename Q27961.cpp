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
	cin.tie(NULL), std::cout.tie(NULL);
 
	setIO("");

	int n;
    cin >> n;

    if(n == 0){
        cout << 0;
    }
    else{
        int ans = 1;
        int cur = 1;
        while(cur < n){
            cur *= 2;
            ans++;
        }
        cout << ans;
    }
 
}
