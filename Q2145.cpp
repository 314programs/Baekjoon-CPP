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

	while(true){
		string s;
		cin >> s;

		if(s == "0"){
			break;
		}

		while(s.length() > 1){
			int total = 0;
			for(auto ch: s){
				total += ch - '0';
			}
			s = to_string(total);
		}
		cout << s << "\n";
		
	}
} 
