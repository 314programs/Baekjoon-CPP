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
		float n;
		string s;
		cin >> n >> s;
		cout << fixed << setprecision(4);

		if(s == "kg"){
			cout << 2.2046*n << " lb";
		}
		if(s == "l"){
			cout << 0.2642*n << " g";
		}
		if(s == "lb"){
			cout << 0.4536*n << " kg";
		}
		if(s == "g"){
			cout << 3.7854*n << " l";
		}
		cout << "\n";
	}


}
