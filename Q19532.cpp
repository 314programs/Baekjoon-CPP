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

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	for(int i = -999; i <= 999; i++){
		for(int j = -999; j <= 999; j++){
			int c_ = a * i + b * j;
			int f_ = d * i + e * j;

			if(c_ == c && f_ == f){
				cout << i << " " << j;
				break;
			}
			
		}
	}
}
