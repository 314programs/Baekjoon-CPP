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
		double a, b, c;
		cin >> a >> b >> c;
		double discriminant = sqrt(b*b - 4*a*c);
		cout << fixed << setprecision(3) << (-b + discriminant)/(2*a) << ", " << (-b - discriminant)/(2*a) << "\n";
	}
	
}
