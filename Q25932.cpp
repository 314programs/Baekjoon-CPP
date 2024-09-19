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
	while(tc--){
		bool zack = false;
		bool mack = false;
		vector<int> a(10);
		for(int i = 0; i < 10; i++){
			cin >> a[i];
			if(a[i] == 18) mack = true;
			if(a[i] == 17) zack = true;
		}

		for(auto ch: a){
			cout << ch << " ";
		}
		cout << "\n";

		if(mack && zack){
			cout << "both\n";
		}
		else if(mack){
			cout << "mack\n";
		}
		else if(zack){
			cout << "zack\n";
		}
		else{
			cout << "none\n";
		}
		if(tc != 0) cout << "\n";
	}
} 
