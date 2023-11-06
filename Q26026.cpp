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
    string s;
    cin >> n >> s;

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1' || s[i] == '!'){
            ans++;
            if(s[i] == '1'){
                if(i+1 < n && s[i+1] == '0') s[i+1] = '!';
                if(i+2 < n && s[i+2] == '0') s[i+2] = '!';
            }
        }
    }
    cout << ans;

 
}
