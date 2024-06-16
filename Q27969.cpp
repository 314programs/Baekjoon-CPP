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
	getline(cin, s);

	vector<string> a;
	string cur = "";
	for(auto ch: s){
		if(ch == ' '){
			a.push_back(cur);
			cur = "";
		}
		else{
			cur += ch;
		}
	}
	a.push_back(cur);

	stack<string> st;
	int ans = 0;
	for(auto ch: a){
		if(ch == "["){
			st.push("]");
		}
		else if(ch == "]"){
			ans += 8;
			st.pop();
		}
		else{
			if(ch[0] - '0' >= 1 && ch[0] - '0' <= 9){
				ans += 8;
			}
			else{
				ans += 12 + ch.length();
			}
		}
	}
	cout << ans;

}
