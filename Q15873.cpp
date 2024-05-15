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

	setIO("");

	string s;
	cin >> s;

	if(s.length() == 2){
		cout << (int)s[0]-'0' + (int)s[1] - '0';
	}
	else if(s.length() == 3){
		if(s[1] == '0'){
			cout << 10 + (int)s[2] - '0';
		}
		else{
			cout << 10 + (int)s[0] - '0';
		}
	}
	else{
		cout << 20;
	}

}
