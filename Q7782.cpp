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

	int n;
	int x, y;
	cin >> n >> x >> y;
	string ans = "No";

	for(int i = 0; i < n; i++){
		int mn_x, mn_y, mx_x, mx_y;
		cin >> mn_x >> mn_y >> mx_x >> mx_y;
		if(mn_x <= x && mx_x >= x && mn_y <= y && mx_y >= y){
			ans = "Yes";
		}
	}

	cout << ans;
	

} 
