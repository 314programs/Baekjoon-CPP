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

	int coldest = 2000;
	bool con = true;
	string ans = "";
	while(con){
		string s;
		int n;
		cin >> s >> n;
		if(s == "Waterloo"){
			con = false;
		}

		if(coldest > n){
			ans = s;
			coldest = n;
		}
	}
	cout << ans;

	

} 
