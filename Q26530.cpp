//still sick
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

int gcd(int a, int b){
	if(a == 0) return b;
	return gcd(b%a, a);
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);
	
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		double ans = 0;
		while(n--){
			string s;
			double m, k;
			cin >> s >> m >> k;
			ans += m*k;
		}
		cout << fixed << setprecision(2) << '$' << ans << "\n";
	}

}
