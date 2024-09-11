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
	getline(cin, s);
	int n = s.length();

	if(s.substr(n-3, n) == "eh?"){
		cout << "Canadian!";
	}
	else{
		cout << "Imposter!";
	}
	
} 
