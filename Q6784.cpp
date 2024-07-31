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
	vector<char> student(n);
	for(int i = 0; i < n; i++){
		cin >> student[i];
	}

	int cnt = 0;
	for(int i = 0; i < n; i++){
		char ans;
		cin >> ans;
		if(student[i] == ans){
			cnt++;
		}
	}
	cout << cnt;
	
}
