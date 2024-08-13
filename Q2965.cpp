//I was tired and thought index started from 1...
//Why did the code not show an error?

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

	vector<int> a(3);
	for(int i = 0; i < 3; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	cout << max(a[2]-a[1], a[1]-a[0]) - 1;

}
