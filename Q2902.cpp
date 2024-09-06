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

	string ans = "";
	ans += s[0];
	bool next = false;
	for(auto ch: s){
		if(next){
			ans += ch;
			next = false;
		}

		if(ch == '-'){
			next = true;
		}
	}
	cout << ans;

}
