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
	double total = 0;
	for(int i = 0; i < n; i++){
		double num;
		cin >> num;
		total += num*num*num;
	}
	cout << fixed << setprecision(7) << pow(total, (double)1/3);
	
}
