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
	cin.ignore();

	while(tc--){
		string s;
		getline(cin, s);

		int n = s.length();
		int ans = 0;
		string cur = "";
		for(int i = 0; i < n; i++){
			if(s[i] == ' '){
				ans += stoi(cur);
				cur = "";
			}
			else{
				cur += s[i];
			}
		}
		ans += stoi(cur);
		cout << ans << "\n";
	}
	

}
