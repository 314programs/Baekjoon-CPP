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

	vector<int> a(10);
	for(int i = 0; i < 10; i++){
		cin >> a[i];
	} 

	int ans = -1;
	for(int i = 0; i < 10; i++){
		for(int j = i+1; j < 10; j++){
			if(ans == -1){
				ans = (a[i]|a[j]);
			}
			else{
				ans ^= (a[i]|a[j]);
			}
		}
	}

	for(int i = 0; i < 10; i++){
		for(int j = i+1; j < 10; j++){
			for(int k = j+1; k < 10; k++){
				ans ^= (a[i]|a[j]|a[k]);
			}
		}
	}
	cout << ans;
	
}
