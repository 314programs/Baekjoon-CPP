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
		double a;
		cin >> a;
		if(a == 0){
			break;
		}

		double cur = 0;
		double val = 2;
		int cnt = 0;
		while(cur < a){
			cur += 1/val;
			val += 1;
			cnt++;
		}
		cout << cnt << " card(s)\n";
	}
	 

} 
