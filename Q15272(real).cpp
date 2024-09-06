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

	string s;
	cin >> s;
	int n = s.length();
	bool can = false;

	for(int i = 0; i < n-1; i++){
		if(s[i] == 's' && s[i+1] == 's'){
			can = true;
		}
	}

	if(can){
		cout << "hiss";
	}
	else{
		cout << "no hiss";
	}

} 
