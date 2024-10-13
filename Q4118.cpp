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

	while(true){
		int n;
		cin >> n;
		if(n == 0) break;

		vector<bool> a(101, false);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 6; j++){
				int num;
				cin >> num;
				a[num] = true;
			}
		}

		string ans = "Yes";
		for(int i = 1; i <= 49; i++){
			if(!a[i]) ans = "No";
		}
		cout << ans << "\n";
	}

}
