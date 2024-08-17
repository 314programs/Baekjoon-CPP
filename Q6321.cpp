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

	int tc;
	cin >> tc;
	for(int i = 1; i <= tc; i++){
		cout << "String #" << i << "\n";
		string s;
		cin >> s;
		for(auto ch: s){
			char cur = ch;
			cur += 1;
			if(cur > 90){
				cur = 65;
			}
			cout << cur;
		}
		cout << "\n";
		if(i != tc) cout << "\n";
	}

}
