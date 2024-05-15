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
		int a, b, c;
		cin >> a >> b >> c;
		if(a == b && b == c){
			ans = max(10000 + (a*1000), ans);
		}
		else if(a == b){
			ans = max(1000 + (a*100), ans);
		}
		else if(b == c){
			ans = max(1000 + (b*100), ans);
		}
		else if(c == a){
			ans = max(1000 + (c*100), ans);
		}
		else{
			ans = max(max({a, b, c})*100, ans);
		}
	}
	cout << ans;

}
