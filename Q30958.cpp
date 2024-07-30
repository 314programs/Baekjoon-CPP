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

	int mx = 0;
	int n;
	cin >> n;
	string s;
	cin.ignore();
	getline(cin, s);

	map<char, int> m;
	for(auto ch: s){
		if(ch == ' ' || ch == ',' || ch == '.') continue;
		m[ch]++;
		mx = max(mx, m[ch]);
	}
	cout << mx;



}
