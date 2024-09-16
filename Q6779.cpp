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

	int h, m;
	cin >> h >> m;
	int ini = -1;
	
	for(int i = 1; i <= m; i++){
		int cur = -6 * pow(i, 4) + h * pow(i, 3) + 2 * pow(i, 2) + i;
		if(cur <= 0 && ini == -1){
			ini = i;
		}
	}

	if(ini == -1){
		cout << "The balloon does not touch ground in the given time.";
	}
	else{
		cout << "The balloon first touches ground at hour: " << ini;
	}
	
}
