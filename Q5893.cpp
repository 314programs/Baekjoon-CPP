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

	string s;
	cin >> s;

	string a = s;
	string b = s + "0000";

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string ans = "";
	
	int idx = 0;
	int carry = 0;
	while(idx < b.length()){
		int cur = carry + (b[idx] - '0');
		if(idx < a.length()) cur += (a[idx] - '0');
		carry = cur/2;
		cur = cur%2;

		ans += cur + '0';
		idx++;
	}
	if(carry == 1) ans += "1";
	reverse(ans.begin(), ans.end());
	cout << ans;

}
