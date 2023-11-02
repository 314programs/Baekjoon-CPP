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

	float n;
	cin >> n;

	float ans = (n*0.01) + 25;
	ans = max(ans, (float)100);
	ans = min(ans, (float)2000);
	cout << fixed << setprecision(2) << ans;
    
}
