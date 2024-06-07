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

	int n;
	cin >> n;
	
	for(int j = 0; j < n; j++){
		cout << string(5*n,'@') << "\n";
	}
	
	for(int i = 0; i < 3; i++){
		string cur = string(n, '@') + string((5*n)-2*(n), ' ') + string(n, '@');
		for(int j = 0; j < n; j++){
			cout << cur << "\n";
		}
	}

	for(int j = 0; j < n; j++){
		cout << string(5*n,'@') << "\n";
	}

}
