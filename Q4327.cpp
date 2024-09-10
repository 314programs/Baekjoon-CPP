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

	while(true){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if(a == 0 && b == 0 && c == 0 && d == 0) break;
		int ans = 120;
		int cur = a;

		while(cur != b){
			cur--;
			if(cur < 0) cur += 40;
			ans++;
		}

		while(cur != c){
			cur++;
			if(cur == 40) cur = 0;
			ans++;
		}

		while(cur != d){
			cur--;
			if(cur < 0) cur += 40;
			ans++;
		}
		cout << ans*9 << "\n";

	}
	
} 
