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

	string a;
	cin >> a;
	int ans = 0;
	for(int i = 0; i < a.length()-3; i++){
		if(a[i] == 'D' && a[i+1] == 'K' && a[i+2] == 'S' && a[i+3] == 'H'){
			ans++;
		}
	}
	cout << ans;

}
