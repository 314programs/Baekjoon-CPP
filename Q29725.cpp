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

	int white = 0;
	int black = 0;
	for(int i = 0; i < 8; i++){
		string s;
		cin >> s;
		for(int j = 0; j < 8; j++){
			if(s[j] == 'P'){
				white += 1;
			}
			else if(s[j] == 'N'){
				white += 3;
			}
			else if(s[j] == 'B'){
				white += 3;
			}
			else if(s[j] == 'R'){
				white += 5;
			}
			else if(s[j] == 'Q'){
				white += 9;
			}

			if(s[j] == 'p'){
				black += 1;
			}
			else if(s[j] == 'n'){
				black += 3;
			}
			else if(s[j] == 'b'){
				black += 3;
			}
			else if(s[j] == 'r'){
				black += 5;
			}
			else if(s[j] == 'q'){
				black += 9;
			}
		}
	}
	cout << white - black;

}
