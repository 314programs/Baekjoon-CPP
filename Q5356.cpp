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
	while(tc--){
		int n;
		char c;
		cin >> n >> c;
		c -= 65;

		for(int i = 1; i <= n; i++){
			cout << string(i, (char)(65+((c+i-1)%26))) << "\n";
		}
		if(tc != 0) cout << "\n";
	}
    
}
