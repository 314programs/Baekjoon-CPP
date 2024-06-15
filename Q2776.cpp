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
		vector<int> a(n);
		map<int, int> mp;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());

		int m;
		cin >> m;
		for(int i = 0; i < m; i++){
			int b;
			cin >> b;

			int l = 0;
			int r = n-1;
			int found = 0;
			while(l <= r){
				int mid = (l+r)/2;
				if(a[mid] == b){
					found = 1;
					break;
				}
				else if(a[mid] > b){
					r = mid-1;
				}
				else{
					l = mid+1;
				}
			}
			cout << found << "\n";
		}
	}

    
}
