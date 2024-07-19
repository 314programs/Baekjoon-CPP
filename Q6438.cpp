//Forgot to cin.ignore() at the start, cost me a lot of trouble
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
	vector<string> a(n);
	cin.ignore();
	for(int i = 0; i < n; i++){
		getline(cin, a[i]);
		a[i].erase(remove(a[i].begin(), a[i].end(), '\n'), a[i].cend());
	}

	for(auto ch: a){
		reverse(ch.begin(), ch.end());
		cout << ch << "\n";
	}


}
