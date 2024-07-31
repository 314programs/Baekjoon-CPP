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
	int rx = -1e9, lx = 1e9, dy = 1e9, uy = -1e9;
	cin >> n;
	while(n--){
		int x, y;
		cin >> x >> y;
		rx = max(rx, x);
		lx = min(lx, x);
		dy = min(dy, y);
		uy = max(uy, y);
	}

	cout << (rx-lx)*(uy-dy);


}
