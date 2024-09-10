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
	int ans = 0;
	while(tc--){
		int a, d, g;
		cin >> a >> d >> g;
		int cur = a * (d+g);
		if(a == d+g){
			cur *= 2;
		}
		ans = max(ans, cur);
	}
	cout << ans;

}
