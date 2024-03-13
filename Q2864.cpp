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

	string a, b;
	cin >> a >> b;

	string max_a = a, max_b = b;
	for(auto &ch: max_a){
		if(ch == '5') ch = '6';
	}
	for(auto &ch: max_b){
		if(ch == '5') ch = '6';
	}

	string min_a = a, min_b = b;
	for(auto &ch: min_a){
		if(ch == '6') ch = '5';
	}
	for(auto &ch: min_b){
		if(ch == '6') ch = '5';
	}

	cout << (stoll(min_a) + stoll(min_b)) << " " << (stoll(max_a) + stoll(max_b));


}
