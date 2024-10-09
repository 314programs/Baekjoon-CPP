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

bool check(string s1, string s2, string cur){
	int total = 0;
	for(int i = 0; i < 4; i++){
		if(s1[i] == cur[i] || s2[i] == cur[i]) total++;
	}
	if(total == 4) return true;
	return false;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	int tc;
	cin >> tc;
	for(int t = 1; t <= tc; t++){
		int n;
		cin >> n;
		cout << "Case " << t << ":\n";

		for(int i = 1; i <= 6; i++){
			for(int j = i; j <= 6; j++){
				if(i+j == n){
					cout << "(" << i << "," << j << ")\n";
				}
			}
		}
	}

}
