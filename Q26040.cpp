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

	cin.ignore();
	string ch;
	getline(cin, ch);

	ch.erase(remove(ch.begin(), ch.end(), ' '), ch.end());
	for(auto c: ch){
		for(auto &cur: s){
			if(cur == c){
				cur += 32;
			}
		}
	}
	cout << s;

}
