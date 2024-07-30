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

	int tc;
	cin >> tc;
	for(int t = 0; t < tc; t++){
		int n;
		cin >> n;
		string s;
		cin >> s;

		for(auto ch: s){
			if(ch == 'b') n--;
			else n++;
		}
		cout << "Data Set " << t+1 << ":\n";
		cout << n << "\n";
		if(t != tc-1) cout << "\n";
	}
}
