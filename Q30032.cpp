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

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;

		for(auto &ch: s){
			if(m == 1){
				if(ch == 'd') ch = 'q';
				else if(ch == 'b') ch = 'p';
				else if(ch == 'q') ch = 'd';
				else if(ch == 'p') ch = 'b';
			}
			else{
				if(ch == 'd') ch = 'b';
				else if(ch == 'b') ch = 'd';
				else if(ch == 'q') ch = 'p';
				else if(ch == 'p') ch = 'q';
			}
		}
		cout << s << "\n";
	}

} 
