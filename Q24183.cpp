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

	float c4 = 0.229 * 0.324 * 2;
	float a3 = 0.297 * 0.42 * 2;
	float a4 = 0.21 * 0.297;
	
	float a, b, c;
	cin >> a >> b >> c;
	cout << fixed << setprecision(5) << a*c4 + b*a3 + c*a4;
}
