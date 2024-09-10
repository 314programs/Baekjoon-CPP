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

	for(int i = 0; i < n/2; i++){
		if(s[i] == '?' && s[n-1-i] != '?'){
			s[i] = s[n-1-i];
		}
		else if(s[i] != '?' && s[n-1-i] == '?'){
			s[n-1-i] = s[i];
		}
		else if(s[i] == '?' && s[n-1-i] == '?'){
			s[i] = 'a';
			s[n-1-i] = 'a';
		}
	}

	if(n%2 == 1 && s[n/2] == '?'){
		s[n/2] = 'a';
	}
	cout << s;

} 
