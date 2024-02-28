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

	int a, p;
	cin >> a >> p;

	a *= 7;
	p *= 13;
	
	if(a > p){
		cout << "Axel";
	}
	else if(a < p){
		cout << "Petra";
	}
	else{
		cout << "lika";
	}

}
