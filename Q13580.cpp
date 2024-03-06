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

	int a, b, c;
	cin >> a >> b >> c;
	if(a+b == c || b+c == a || c+a == b || a == b || b == c || a == c){
		cout << "S";
	}
	else{
		cout << "N";
	}

}
