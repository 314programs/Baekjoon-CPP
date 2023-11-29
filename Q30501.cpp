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

	int n;
	cin >> n;
	vector<string> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(auto ch: a){
		for(auto c: ch){
			if(c == 'S'){
				cout << ch;
			}
		}
	}
	
}
