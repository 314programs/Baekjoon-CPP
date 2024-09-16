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

	double p1, g1;
	cin >> p1 >> g1;
	double ans = (1000.0/g1) * p1;

	int n;
	cin >> n;
	while(n--){
		double p, g;
		cin >> p >> g;
		ans = min(ans, (1000.0/g)*p);
	}
	cout << fixed << setprecision(2) << ans;

    
}
