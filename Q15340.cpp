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
		cin >> a >> b;

		if(a == 0 && b == 0) break;

		cout << min({(a*30 + b*40), (a*35 + b*30), (a*40 + b*20)}) << "\n";

	}

}
