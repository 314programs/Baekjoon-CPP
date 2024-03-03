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
		int n, m;
		cin >> n >> m;

		vector<int> a(n);
		vector<int> b(m);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < m; i++){
			cin >> b[i];
		}

		int i = 0, j = 0;
		int ans = 0;
		while(i < n && j < m){
			if(a[i] == b[j]){
				ans++;
				i++; j++;
			}
			else if(a[i] > b[j]){
				j++;
			}
			else{
				i++;
			}
		}
		cout << ans << "\n";
	}
    
    
}
