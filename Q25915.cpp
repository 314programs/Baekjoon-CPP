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

	string t;
	cin >> t;
	string s = t + "ILOVEYONSEI";
	int n = s.length();

	int ans = 0;
	for(int i = 0; i < n-1; i++){
		ans += abs(s[i] - s[i+1]);
	}
	cout << ans;


}
