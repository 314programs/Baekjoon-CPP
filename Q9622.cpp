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
		float a, b, c, d;
		cin >> a >> b >> c >> d;

		if((a <= 56 && b <= 45 && c <= 25 || a+b+c <= 125) && d <= 7){
			cout << "1\n";
			ans++;
		}
		else{
			cout << "0\n";
		}
	}
	cout << ans;
	

} 
