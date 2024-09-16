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
		int a1, a2, a3;
		cin >> a1 >> a2 >> a3;
		if(a1 == 0 && a2 == 0){
			break;
		}
		if(a2 - a1 == a3 - a2){
			cout << "AP " << a3 + (a3 - a2) << "\n";
		}
		else{
			cout << "GP " << a3 * (a3/a2) << "\n";
		}
	}

    
}
