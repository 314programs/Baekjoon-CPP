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
		double a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		double ans = (a*350.34) + (b*230.90) + (c*190.55) + (d*125.30) + (e*180.90);
		cout << fixed << setprecision(2) << "$" << ans << "\n";
	}

    
}
