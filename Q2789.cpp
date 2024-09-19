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

	string cam = "CAMBRIDGE";
	string s;
	cin >> s;

	for(auto ch: s){
		bool can = true;
		for(auto ci: cam){
			if(ci == ch){
				can = false;
				break;
			}
		}
		if(can) cout << ch;
	}

}
