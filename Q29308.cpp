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

	int n;
	cin >> n;
	int mx = 0;
	string ans = "";

	while(n--){
		int a;
		string b, c;
		cin >> a >> b >> c;

		if(a > mx && c == "Russia"){
			mx = a;
			ans = b;
		}
	}
	cout << ans;

}
