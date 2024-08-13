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
	if(n == 0){
		cout << 1;
	}
	else if(n == 1){
		cout << 0;
	}
	else{
		if(n%2 == 1){
			cout << 4;
			n--;
		}
		while(n > 0){
			cout << 8;
			n -= 2;
		}
	}
	
}
