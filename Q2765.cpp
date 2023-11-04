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

	const float pi = 3.1415927;
	int cnt = 1;
	while(true){
		float r, turn, t;
		cin >> r >> turn >> t;
		if(turn == 0) break;
		float dist = (r*pi*turn)/(5280*12);
		cout << fixed << "Trip #" << cnt << ": " << setprecision(2) << dist << " " << (dist/t)*60*60 << "\n";
		cnt++;
	}
}
