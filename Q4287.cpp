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

	while(true){
		string a, b, c;
		cin >> a;
		if(a == "#") break;
		cin >> b >> c;
		int n = a.length();

		vector<int> increase(n);
		for(int i = 0; i < n; i++){
			increase[i] = (int)(b[i] - a[i]);
		}

		string ans = "";
		for(int i = 0; i < n; i++){
			ans += ((c[i] - 'a' + increase[i] + 26)%26) + 'a';
		}
		cout << a << " " << b << " " << c << " " << ans << "\n";
	}
	
}
