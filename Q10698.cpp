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
		int a, b, c;
		char op, eq;
		cin >> a >> op >> b >> eq >> c;

		string ans = "NO";
		if(op == '+' && a + b == c){
			ans = "YES";
		}
		if(op == '-' && a - b == c){
			ans = "YES";
		}

		cout << "Case " << cnt << ": " << ans << "\n";
		cnt++;
	}

}
