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
	while(tc--){
		int n;
		cin >> n;

		vector<int> a(9, 0);
		for(int i = 0; i < n; i++){
			int c, b;
			cin >> c >> b;
			a[b]++;
		}

		int mx = 0;
		int ans = 1;
		for(int i = 1; i <= 8; i++){
			if(a[i] > mx){
				mx = a[i];
				ans = i;
			}
		}
		cout << mx << "\n";
	}

}
