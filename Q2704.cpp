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
		string s;
		cin >> s;
		bitset<6> h = stoll(s.substr(0, 2));
		bitset<6> m = stoll(s.substr(3, 5));
		bitset<6> sc = stoll(s.substr(6, 9));

		string h_s = h.to_string();
		string m_s = m.to_string();
		string sc_s = sc.to_string();

		for(int i = 0; i < 6; i++){
			cout << h_s[i] << m_s[i] << sc_s[i];
		}
		cout << " " << h << m << sc << "\n";
	}

}
