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

	string s;
	cin >> s;
	reverse(s.begin(), s.end());

	string n;
	int cnt = 0;
	for(auto ch: s){
		if(cnt == 3){
			n += ',';
			cnt = 0;
		}
		cnt++;
		n += ch;
	}
	reverse(n.begin(), n.end());
	cout << n;
}
