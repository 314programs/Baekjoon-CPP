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

	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		cout << "Pairs for " << n << ": ";
		vector<pair<int, int>> a;
		for(int i = 1; i <= n/2; i++){
			if(i != n-i && n-i != 0){
				a.push_back({i, n-i});
			}
		}

		if(a.size() > 1){
			for(int i = 0; i < a.size()-1; i++){
				cout << a[i].first << " " << a[i].second << ", ";
			}
			cout << a[a.size()-1].first << " " << a[a.size()-1].second << "\n";
		}
		else if(a.size() == 1){
			cout << a[0].first << " " << a[0].second << "\n";
		}
		else{
			cout << "\n";
		}

	}

}
