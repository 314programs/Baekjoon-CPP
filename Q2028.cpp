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
		int n;
		cin >> n;
		int multi = n*n;
		string a = to_string(n);
		string b = to_string(multi);

		if(b.substr(b.length()-a.length(), b.length()) == a){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	

} 
