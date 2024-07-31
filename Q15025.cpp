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

	int l, r;
	cin >> l >> r;

	if(l == 0 && r == 0){
		cout << "Not a moose";
	}
	else if(l == r && l != 0){
		cout << "Even " << l+r;
	}
	else{
		cout << "Odd " << max(l, r) * 2;
	}
}
