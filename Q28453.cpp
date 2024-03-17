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

	int n;
	cin >> n;
	while(n--){
		int m;
		cin >> m;
		if(m >= 300){
			cout << 1 << " ";
		}
		else if(m >= 275){
			cout << 2 << " ";
		}
		else if(m >= 250){
			cout << 3 << " ";
		}
		else{
			cout << 4 << " ";
		}
	}
    
}
