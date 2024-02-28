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
		cin >> n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == 0 || i == n-1 || j == 0 || j == n-1){
					cout << '#';
				}
				else{
					cout << 'J';
				}
			}
			cout << "\n";
		}
		if(tc != 0) cout << "\n";
	}

    
}
