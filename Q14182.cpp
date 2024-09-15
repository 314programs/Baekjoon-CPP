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
	cin.tie(NULL), cout.tie(NULL);

	while(true){
		int cur;
		cin >> cur;
		if(cur == 0) break;

		if(cur <= 1000000){
			cout << fixed << setprecision(0) << cur << "\n";
		}
		else if(cur <= 5000000){
			cout << fixed << setprecision(0) << cur - cur*0.1f << "\n";
		}
		else{
			cout << fixed << setprecision(0) << cur - cur*0.2f << "\n";
		}
	}
} 
