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
	cin >> n;
	string s;
	cin >> s;

	for(int i = 0; i < n; i++){
		int s_cnt = 0;
		int c_cnt = 0;
		for(int j = i; j < n; j++){
			if(s[j] == 's') s_cnt++;
			else c_cnt++;
		}
		if(s_cnt == c_cnt){
			cout << s.substr(i, n);
			break;
		}
	}

}
