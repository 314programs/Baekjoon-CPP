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

	string s;
	cin >> s;
	cin.ignore();

	int n = 0;

	string str;
	while(cin >> str){
		if(str.length() >= s.length()){
			for(int i = 0; i + s.length() <= str.length(); i++){
				if(str.substr(i, i + s.length()) == s){
					n++;
				}
			}
		}
	}
	cout << n;

}
