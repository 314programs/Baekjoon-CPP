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
	getline(cin, s);
	string ans = "";

	for(auto ch: s){
		if(ch >= 97 && ch <= 122){
			if(ch - 97 + 1 > 9){
				ans += to_string(ch - 97 + 1);
			}
			else{
				ans += "0";
				ans += to_string(ch - 97 + 1);
			}
		}
		else if(ch >= 65 && ch <= 90){
			ans += to_string(ch - 65 + 27);
		}
		else if(ch-'0' >= 0 && ch-'0' <= 9){
			ans += "#";
			ans += ch;
		}
		else{
			ans += ch;
		}
	}
	cout << ans;



} 
