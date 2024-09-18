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

	bool M = false, O = false, B = false, I = false, S = false;

	for(auto ch: s){
		if(ch == 'M') M = true;
		if(ch == 'O') O = true;
		if(ch == 'B') B = true;
		if(ch == 'I') I = true;
		if(ch == 'S') S = true;
	}

	if(M && O && B && I && S){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
    
}
