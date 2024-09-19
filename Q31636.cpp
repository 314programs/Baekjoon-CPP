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

    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = "No";
    for(int i = 0; i <= n-3; i++){
        if(s[i] == s[i+1] && s[i] == s[i+2] && s[i] == 'o'){
            ans = "Yes";
            break;
        }
    }
    cout << ans;

}
