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
	while(tc--){
		int n, m;
		cin >> n >> m;
		map<int, int> mp;
		int ans = 0;
		while(n--){
			int num;
			cin >> num;
			if(mp[num] == 0){
				mp[num] = 1;
			}
			else{
				ans++;
			}
		}
		cout << ans << '\n';
	}
	
} 
