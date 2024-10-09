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
	int cnt = 1;
	while(tc--){
		int n, p, q;
		cin >> n >> p >> q;
		
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());

		int cur = 0;
		int eggs = 0;
		while(cur <= q && eggs < n){
			cur += a[eggs++];
		}

		if(cur > q) eggs--;
		cout << "Case " << cnt << ": " << min(eggs, p) << "\n";

		cnt++;
	}

}
