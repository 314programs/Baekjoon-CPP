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

	while(true){
		float x, y;
		cin >> x >> y;
		if(x == 0 || y == 0){
			cout << "AXIS\n";
			if(x == 0 && y == 0){
				break;
			}
		}
		else if(x > 0 && y > 0){
			cout << "Q1\n";
		}
		else if(x > 0 && y < 0){
			cout << "Q4\n";
		}
		else if(x < 0 && y < 0){
			cout << "Q3\n";
		}
		else{
			cout << "Q2\n";
		}

	}

}
