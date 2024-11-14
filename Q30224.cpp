//#include <bits/stdc++.h>
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

	int a;
	cin >> a;

	bool contain = false;
	bool divisible = false;

	for(auto ch: to_string(a)){
		if(ch == '7'){
			contain = true;
		}
	}

	if(a%7 == 0) divisible = true;

	if(!contain && !divisible) cout << "0";
	else if(!contain && divisible) cout << "1";
	else if(contain && !divisible) cout << "2";
	else cout << "3";


}
