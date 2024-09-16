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
		set<char> st;
		for(auto ch: s){
			st.insert(ch);
		}
		cout << st.size() << "\n";
	}

} 
