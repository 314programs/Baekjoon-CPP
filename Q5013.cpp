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
		string s;
		cin >> s;
		int n = s.length();

		int add = 1;
		for(int i = 0; i < n-1; i++){
			if(s[i] == 'C' && s[i+1] == 'D'){
				add = 0;
				break;
			}
		}
		ans += add;
	}
	cout << ans;

} 
