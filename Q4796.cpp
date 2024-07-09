//v%p can be larger than l... i forgot that
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

	int cnt = 1;
	while(true){
		int l, p, v;
		cin >> l >> p >> v;
		if(l == 0 && p == 0 && v == 0) break;
		cout << "Case " << cnt << ": " << min(v%p, l) + (v/p)*(l) << "\n";
		cnt++;
	}

}
