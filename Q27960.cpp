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

	int a, b;
	cin >> a >> b;

	int c = 0;
	for(int i = 0; i <= 9; i++){
		if(a & (1 << i) ^ b & (1 << i)){
			c += (1 << i);
		}
	}
	cout << c;

}
