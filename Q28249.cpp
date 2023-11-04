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

	int tc;
	cin >> tc;
	int ans = 0;
	while(tc--){
		string s;
		cin >> s;
		if(s == "Poblano"){
			ans += 1500;
		}
		if(s == "Mirasol"){
			ans += 6000;
		}
		if(s == "Serrano"){
			ans += 15500;
		}
		if(s == "Cayenne"){
			ans += 40000;
		}
		if(s == "Thai"){
			ans += 75000;
		}
		if(s == "Habanero"){
			ans += 125000;
		}
	}
	cout << ans;
    
}
