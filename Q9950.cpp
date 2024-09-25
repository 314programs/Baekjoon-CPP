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

	while(true){
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 0 && b == 0 && c == 0) break;

		if(a == 0){
			cout << c/b << " " << b << " " << c << "\n";
		}
		else if(b == 0){
			cout << a << " " << c/a << " " << c << "\n";
		}
		else{
			cout << a << " " << b << " " << a*b << "\n";
		}
	}

} 
