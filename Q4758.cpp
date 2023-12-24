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

	while(true){
		float a, b, c;
		cin >> a >> b >> c;

		if(a == 0 && b == 0 && c == 0){
			break;
		}

		bool can = false;
		if(a <= 4.5 && b >= 150 && c >= 200){
			cout << "Wide Receiver ";
			can = true;
		}
		if(a <= 6 && b >= 300 && c >= 500){
			cout << "Lineman ";
			can = true;
		}
		if(a <= 5 && b >= 200 && c >= 300){
			cout << "Quarterback ";
			can = true;
		}
		if(!can){
			cout << "No positions";
		}
		cout << "\n";

	}
}
