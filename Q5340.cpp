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

	vector<string> a(6);
	for(int i = 0; i < 6; i++){
		string s;
		getline(cin, s);
		int n = s.length();

		if(s[n-1] == ' '){
			n--;
		}
		a[i] = to_string(n);
	}

	cout << "Latitude " + a[0] + ":" + a[1] + ":" + a[2] + "\n";
	cout << "Longitude " + a[3] + ":" + a[4] + ":" + a[5];

	

} 
