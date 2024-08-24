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
		int a = stoll(s);
		reverse(s.begin(), s.end());
		int b = stoll(s);
		a += b;

		string c = to_string(a);
		string d = c;
		reverse(d.begin(), d.end());

		if(c == d) cout << "YES\n";
		else cout << "NO\n";
	}


} 
