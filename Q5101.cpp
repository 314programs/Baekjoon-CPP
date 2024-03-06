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

	while(true){
		int s, d, n;
		cin >> s >> d >> n;
		if(s == 0 && d == 0 && n == 0){
			break;
		}
		if(abs(n - s)%d == 0 && ((n > s && d > 0) || (n < s && d < 0) || (n == s))){
			cout << abs(n-s)/d + 1 << "\n";
		}
		else{
			cout << "X\n";
		}
	}
	
}
