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
	
	map<int, int> m;
	for(int i = 0; i < 5; i++){
		int a;
		cin >> a;
		m[a]++;
	}

	for(auto [a, b]: m){
		if(b%2 == 1) cout << a;
	}


}
