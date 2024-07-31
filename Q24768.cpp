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
		int a, b;
		cin >> a >> b;
		if(a == 0 && b == 0) break;
		
		if(a + b == 13){
			cout << "Never speak again.\n";
		}
		else if(a > b){
			cout << "To the convention.\n";
		}
		else if(a == b){
			cout << "Undecided.\n";
		}
		else{
			cout << "Left beehind.\n";
		}
	}

}
