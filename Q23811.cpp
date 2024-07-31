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
	
	for(int i = 0; i < 5; i++){
		int cnt;
		if(i%2 == 0) cnt = 5;
		else cnt = 1;

		string cur = string(cnt*n, '@');
		for(int j = 0; j < n; j++){
			cout << cur << "\n";
		}
	}

}
