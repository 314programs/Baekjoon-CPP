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
	int cnt = 0;
	for(int i = 1; i <= 500; i++){
		for(int j = i+1; j <= 500; j++){
			if(j*j - i*i == n){
				cnt++;
			}
		}
	}
	cout << cnt;

    
}
