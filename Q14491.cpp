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
	int cur = 1;
	while(cur <= n){
		cur *= 9;
	}
	cur /= 9;

	string ans = "";
	while(cur != 0){
		if(n - cur >= 0){
			for(int i = 9; i >= 1; i--){
				if(n - cur*i >= 0){
					ans += to_string(i);
					n -= cur*i;
					break;
				}
			}
		}
		else{
			ans += "0";
		}
		cur /= 9;
	}
	cout << ans;

}
