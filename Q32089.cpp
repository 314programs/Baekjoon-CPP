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

	while(true){
		int n;
		cin >> n;
		if(n == 0) break;

		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int ans = 0;
		for(int i = 0; i < n-2; i++){
			if(a[i] + a[i+1] + a[i+2] > ans){
				ans = a[i] + a[i+1] + a[i+2];
			}
		}
		cout << ans << "\n";
	}

} 
