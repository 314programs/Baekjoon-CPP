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
	int cnt = 1;
	while(tc--){
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b(n);

		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		reverse(b.begin(), b.end());

		int ans = 0;
		for(int i = 0; i < n; i++){
			ans += a[i] * b[i];
		}
		cout << "Case #" << cnt++ << ": " << ans << "\n";
	}

}
