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

	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;

		int total = 0;
		float gpa = 0;
		for(int i = 0; i < n; i++){
			int t;
			float g;
			cin >> t >> g;
			total += t;
			gpa += (t*g);
		}
		cout << total << " " << fixed << setprecision(1) << gpa/(total) << "\n";
	}

}
