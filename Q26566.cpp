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
	while(tc--){
		float a1, p1, a2, p2;
		cin >> a1 >> p1 >> a2 >> p2;

		float slice = a1/p1;
		float whole = (a2*a2*M_PI)/p2;

		if(whole > slice){
			cout << "Whole pizza\n";
		}
		else{
			cout << "Slice of pizza\n";
		}
	}
    
}
