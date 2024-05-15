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

	int want_floor, lift_floor, stair, lift;
	cin >> want_floor >> lift_floor >> stair >> lift;

	int lift_time = lift_floor - 1 + want_floor - 1;
	cout << lift_time * lift << " " << stair * (want_floor - 1);
	
}
