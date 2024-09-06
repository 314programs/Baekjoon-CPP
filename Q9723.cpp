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
		cout << "Case #" << cnt++ << ": ";
		vector<int> a(3);
		for(int i = 0; i < 3; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());

		if(a[0]*a[0] + a[1]*a[1] == a[2]*a[2]){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	

} 
