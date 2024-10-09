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

	int a, b, c;
	cin >> a >> b >> c;

	string handle = "*" + string(b, ' ') + "*" + string(b, ' ') + "*";
	for(int i = 0; i < a; i++){
		cout << handle << "\n";
	}
	cout << string((3 + b*2), '*') << "\n";;

	for(int i = 0; i < c; i++){
		cout << string(b+1, ' ') << "*\n";
	}


} 
