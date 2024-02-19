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

	int a[303];
	a[1] = 1;
	for(int i = 1; i <= 301; i++){
		a[i+1] = a[i] + i+1;
	}
	
	while(tc--){
		int n;
		cin >> n;
		int result = 0;

		for(int i = 1; i <= n; i++){
			result += a[i+1] * i;
		}
		cout << result << "\n";
	}

    
}
