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
	for(auto ch: s){
		if(ch == 'I') cout << "E";
		else if(ch == 'E') cout << "I";
		else if(ch == 'S') cout << "N";
		else if(ch == 'N') cout << "S";
		else if(ch == 'T') cout << "F";
		else if(ch == 'F') cout << "T";
		else if(ch == 'J') cout << "P";
		else if(ch == 'P') cout << "J";
	}
}
