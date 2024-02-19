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

	int t1, t2;
	cin >> t1 >> t2;
	int cnt = 2;
	while(!(t1 < t2)){
		int t3 = t1 - t2;
		t1 = t2;
		t2 = t3;
		cnt++;
	}
	cout << cnt;

}
