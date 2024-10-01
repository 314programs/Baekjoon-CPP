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

bool check(string s1, string s2, string cur){
	int total = 0;
	for(int i = 0; i < 4; i++){
		if(s1[i] == cur[i] || s2[i] == cur[i]) total++;
	}
	if(total == 4) return true;
	return false;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;

	int ans = 0;
	for(int i = 0; i <= 9999; i++){
		string cur = to_string(i);
		while(cur.length() < 4){
			cur = '0' + cur;
		}

		if(check(s1, s2, cur)){
			ans++;
		}
	}
	cout << ans;

}
