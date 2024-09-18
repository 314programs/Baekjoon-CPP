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

	int n;
	cin >> n;
	vector<string> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int m;
	cin >> m;
	if(m == 1){
		for(int i = 0; i < n; i++){
			cout << a[i] << "\n";
		}
	}
	else if(m == 2){
		for(int i = 0; i < n; i++){
			reverse(a[i].begin(), a[i].end());
			cout << a[i] << "\n";
		}
	}
	else if(m == 3){
		for(int i = n-1; i >= 0; i--){
			cout << a[i] << "\n";
		}
	}

}
