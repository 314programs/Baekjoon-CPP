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

	int tc;
	cin >> tc;
	int ans = 0;
	while(tc--){
		int a, b;
		cin >> a >> b;
		if(a == 136) ans += 1000;
		if(a == 142) ans += 5000;
		if(a == 148) ans += 10000;
		if(a == 154) ans += 50000;
	}
	cout << ans;

}
