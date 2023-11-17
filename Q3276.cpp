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

	string ans;
	int min_ans = 10000;

	for(int i = 1; i <= 10; i++){
		for(int j = 1; j <= 10; j++){
			if(i * j >= n && i + j < min_ans){
				ans = to_string(i) + " " + to_string(j);
				min_ans = i+j;
			}
		}
	}
	cout << ans;
	
}
