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

bool compare(const pair<string, string> a, const pair<string, string> b){
	return a.second < b.second;
}

int32_t main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int tc;
	cin >> tc;
	while(tc--){
		string s;
		int n;
		cin >> s >> n;
		cin.ignore();

		vector<string> a;
		for(int i = 0; i < n; i++){
			string cur; 
			getline(cin, cur);

			string temp = "";
			vector<string> store;
			for(auto ch: cur){
				if(ch == ' '){
					store.push_back(temp);
					temp = "";
				}
				else{
					temp += ch;
				}
			}
			store.push_back(temp);

			if(store.size() == s.length()){
				bool can = true;
				for(int i = 0; i < s.length(); i++){
					if(store[i][0] != s[i]){
						can = false;
					}
				}

				if(can){
					a.push_back(cur);
				}
			}
		}

		cout << s << "\n";
		for(auto ch: a){
			cout << ch << "\n";
		}
	}

} 
