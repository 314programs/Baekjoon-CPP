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

	setIO("");

	int n;
	cin >> n;
	cout << "int a;\nint *ptr = &a;\n";
	string prev = "ptr";
	
	for(int i = 2; i <= n; i++){
		cout << "int " << string(i, '*') << "ptr" << i << " = &" << prev << ";\n";
		prev = "ptr" + to_string(i); 
	}

}
