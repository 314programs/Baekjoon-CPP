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
		int sum = 0;

		for(int i = 1; i < n; i++){
			if(n%i == 0){
				sum += i;
			}
		}

		cout << n << " is a";
		if(sum == n){
			cout << " perfect number.\n";
		}
		else if(sum < n){
			cout << " deficient number.\n";
		}
		else{
			cout << "n abundant number.\n";
		}
		if(tc != 0) cout << "\n";
	}
	
}
