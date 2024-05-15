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

	int n;
	cin >> n;

	int a = 1;
	int ans = 0;

	while(a < ((int)1 << 31)){
		if(a == n){
			ans = 1;
			break;
		}
		a *= 2;
	}
	cout << ans;

}
