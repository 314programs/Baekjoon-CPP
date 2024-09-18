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
		int a, b, c;
		cin >> a >> b >> c;
		cout << a << " " << b << " " << c << " ";
		if(a+b+c == 180){
			cout << "Seems OK\n";
		}
		else{
			cout << "Check\n";
		}
	}

} 
