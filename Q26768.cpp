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
		if(ch == 'a'){
			cout << '4';
		}
		else if(ch == 'e'){
			cout << '3';
		}
		else if(ch == 'i'){
			cout << '1';
		}
		else if(ch == 'o'){
			cout << '0';
		}
		else if(ch == 's'){
			cout << '5';
		}
		else{
			cout << ch;
		}
	}
	
}
