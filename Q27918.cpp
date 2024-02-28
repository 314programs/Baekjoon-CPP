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

	int d = 0, p = 0;
	bool done = false;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		if(c == 'D') d++;
		else p++;

		if(abs(d-p) >= 2 && !done){
			cout << d << ":" << p;
			done = true;
		}
	}
	if(!done) cout << d << ":" << p;

}
