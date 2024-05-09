//need to develop game...
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

	setIO("");

	int f, s;
	cin >> f >> s;

	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;

		cout << n << " ";
		if(n <= 1000){
			cout << f*n << '\n';
		}
		else{
			cout << 1000 * f + (n - 1000) * s << '\n';
		}
	}
    
    
}
