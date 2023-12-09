//Overflow jumpscare...
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
		cin.ignore();
		int n;
		cin >> n;

		int sum = 0;
		for(int i = 0; i < n; i++){
			int num;
			cin >> num;
			sum += num;
			sum %= n;
		}

		if(sum%n == 0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
    
}
