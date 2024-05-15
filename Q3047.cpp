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

	vector<int> a(3);
	for(int i = 0; i < 3; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	string s;
	cin >> s;
	for(auto ch: s){
		cout << a[ch-'A'] << " ";
	}


}
