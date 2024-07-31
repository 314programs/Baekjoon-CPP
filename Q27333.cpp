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

	int n;
	string s;
	cin >> n >> s;

	for(int i = 0; i < n; i++){
		if(s[i] == s[i+1] && s[i] == 'j'){
			s[i] = 'J';
			s[i+1] = 'J';
		}
		if(s[i] == s[i+1] && s[i] == 'o'){
			s[i] = 'O';
			s[i+1] = 'O';
		}
		if(s[i] == s[i+1] && s[i] == 'i'){
			s[i] = 'I';
			s[i+1] = 'I';
		}
	}

	cout << s;

} 
