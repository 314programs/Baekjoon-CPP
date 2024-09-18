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
	cin.tie(NULL), cout.tie(NULL);

	int tc;
	cin >> tc;
	double ans = 0;
	double const pi = 3.14159;
	while(tc--){
		char c;
		cin >> c;
		if(c == 'S'){
			double r;
			cin >> r;
			ans = max(ans, (4.0/3.0) * pi * r * r * r);
		}
		else if(c == 'C'){
			double r, h;
			cin >> r >> h;
			ans = max(ans, (1.0/3.0) * pi * r * r * h);
		}
		else if(c == 'L'){
			double r, h;
			cin >> r >> h;
			ans = max(ans, pi * r * r * h);
		}
	}
	cout << fixed << setprecision(3) << ans;
	
} 
