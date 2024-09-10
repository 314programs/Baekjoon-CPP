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

	int n, m;
	cin >> n >> m;

	string c, s;
	cin >> c >> s;

	string p_text = c;
	for(int i = m-1; i >= n; i--){
		int prev = 0;
		while(true){
			if((prev + (p_text[n-1]-'a'))%26 == (s[i]-'a')){
				break;
			}
			prev++;
		} 
		p_text = (char)(prev+'a') + p_text;
	}
	cout << p_text;
	
} 
