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

	vector<int> a(5);
	vector<int> b(5);
	string ans = "Y";
	for(int i = 0; i < 5; i++){
		cin >> a[i];
	}
	for(int i = 0; i < 5; i++){
		cin >> b[i];
		if(a[i] == b[i]) ans = "N";
	}
	cout << ans;
} 
