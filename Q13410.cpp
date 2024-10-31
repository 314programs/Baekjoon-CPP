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

	int a, b;
	cin >> a >> b;
	int mx = 0;

	for(int i = 1; i <= b; i++){
		string cur = to_string(i*a);
		reverse(cur.begin(), cur.end());
		mx = max(mx, stoll(cur));
	}
	cout << mx;


}
