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

	int tc;
	cin >> tc;
	int a_cnt = 0, b_cnt = 0;
	while(tc--){
		int a, b;
		cin >> a >> b;
		if(a > b){
			a_cnt += a+b;
		}
		else if(b > a){
			b_cnt += a+b;
		}
		else{
			a_cnt += a;
			b_cnt += b;
		}
	}
	cout << a_cnt << " " << b_cnt;

	
}
