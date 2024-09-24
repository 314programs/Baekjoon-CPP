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

	map<string, pair<int, int>> m;
	m["black"] = pair(0, 1);
	m["brown"] = pair(1, 10);
	m["red"] = pair(2, 100);
	m["orange"] = pair(3, 1000);
	m["yellow"] = pair(4, 10000);
	m["green"] = pair(5, 100000);
	m["blue"] = pair(6, 1000000);
	m["violet"] = pair(7, 10000000);
	m["grey"] = pair(8, 100000000);
	m["white"] = pair(9, 1000000000);

	string digit = "";
	for(int i = 0; i < 2; i++){
		string s;
		cin >> s;
		digit += to_string(m[s].first);
	}

	string s;
	cin >> s;
	cout << m[s].second * stoll(digit);

} 
