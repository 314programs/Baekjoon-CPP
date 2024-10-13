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

	int n;
	cin >> n;

	vector<int> a(n);
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	for(int i = 0; i < n-1; i++){
		ans += (a[i+1] - a[i]) * (a[i+1] - a[i]);
	}
	cout << ans;

}
