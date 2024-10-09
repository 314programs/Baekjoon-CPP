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

	vector<char> symbols = {'+','_',')','(','*','&','^','%','$','#','@','!','.','/',',',';','{','}'};
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		string s;
		cin >> s;

		vector<int> checker = {0,0,0,0,0};
		for(auto ch: s){
			if(ch >= 'A' && ch <= 'Z'){
				checker[0] = 1;
			}
			else if(ch >= 'a' && ch <= 'z'){
				checker[1] = 1;
			}
			else if(ch >= '0' && ch <= '9'){
				checker[2] = 1;
			}

			for(auto cur: symbols){
				if(cur == ch) checker[3] = 1;
			}
		}
		if(n >= 12) checker[4] = 1;

		int total = 0;
		for(int i = 0; i < 5; i++){
			total += checker[i];
		}
		
		if(total == 5){
			cout << "valid\n";
		}
		else{
			cout << "invalid\n";
		}
	}

} 
