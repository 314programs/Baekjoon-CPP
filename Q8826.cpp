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

	int tc;
	cin >> tc;
	while(tc--){
		int num;
		string s;
		cin >> num >> s;

		int x = 0;
		int y = 0;

		for(auto ch: s){
			if(ch == 'N') y++;
			else if(ch == 'S') y--;
			else if(ch == 'E') x++;
			else x--;
		}

		cout << abs(x) + abs(y) << "\n";
	}

}
