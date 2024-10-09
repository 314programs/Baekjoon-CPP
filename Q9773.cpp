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

	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;

		int a = 0;
		for(auto ch: s){
			a += ch-'0';
		}

		int b = stoi(s.substr(10, 13)) * 10;
		int c = a + b;
		if(c < 1000){
			c += 1000;
		}
		else if(c > 9999){
			c %= 10000;
		}
		string ans = to_string(c);
		while(ans.length() < 4){
			ans = "0" + ans;
		}
		cout << ans << "\n";
	}

} 
