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
		string s;
		cin >> s;

		string ans;
		ans = tolower(s[0]);
		int n = s.length();

		for(int i = 1; i < n; i++){
			if((int)s[i] < 90){
				ans += "_";
				ans += tolower(s[i]);
			}
			else{
				ans += s[i];
			}
		}
		cout << ans << '\n';
	}
    
    
}
