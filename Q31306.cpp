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
	int v_cnt = 0;
	int y_cnt = 0;
	cin >> s;

	for(auto ch: s){
		if(ch == 'y') y_cnt++;
		else if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
			v_cnt++;
		}
	}
	cout << v_cnt << " " << v_cnt + y_cnt;

}
