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
	cin.tie(NULL), std::cout.tie(NULL);

	while(true){
		int a, b;
		char c;
		cin >> a >> c >> b;
		if(a == 0 && b == 0) break;
		if(c == 'W'){
			if(a - b < -200){
				cout << "Not allowed\n";
			}
			else{
				cout << a-b << '\n';
			}
		}
		else{
			cout << a + b << "\n";
		}
	}

}
