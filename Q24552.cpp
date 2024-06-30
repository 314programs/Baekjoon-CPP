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

	int pair = 0;
	int open = 0;
	int close = 0;
	bool printed = false;

	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			open++;
			pair++;
		}
		else{
			close++;
			pair--;
		}
		if(pair < 0){
			cout << close;
			printed = true;
			break;
		}
		else if(pair == 0){
			open = 0;
		}
	}
	if(!printed){
		cout << open;
	}

}
