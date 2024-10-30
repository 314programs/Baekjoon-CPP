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
	cin.ignore();
	while(tc--){
		string a, b;
		double x1, y1, z1, x2, y2, z2;
		getline(cin, a);
		cin >> x1 >> y1 >> z1;
		cin.ignore();
		getline(cin, b);
		cin >> x2 >> y2 >> z2;
		cin.ignore();
		cout << fixed << setprecision(2) << a << " to " << b << ": " << sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1)) << "\n";
	}

}
