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
	int t;
	cin >> t;

	while(true){
		int n;
		cin >> n;
		if(n == 0) break;
		
		if(n%t != 0){
			cout << n << " is NOT a multiple of " << t << ".\n";
		}
		else{
			cout << n << " is a multiple of " << t << ".\n";
		}
	}


}
