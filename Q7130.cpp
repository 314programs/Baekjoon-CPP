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

	int milk_h, honey_h;
	cin >> milk_h >> honey_h;

	int n;
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++){
		int m, h;
		cin >> m >> h;
		ans += max(m*milk_h, h*honey_h);
	}
	cout << ans;
	
}
