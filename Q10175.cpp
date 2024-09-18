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

	map<char, int> mp;
	int tc;
	cin >> tc;
	while(tc--){
		mp.clear();
		string s;
		string i;
		cin >> s >> i;
		for(auto ch: i){
			if(ch == 'B') mp[ch] += 2;
			else if(ch == 'C') mp[ch] += 1;
			else if(ch == 'M') mp[ch] += 4;
			else if(ch == 'W') mp[ch] += 3;
		}

		int cur = 0;
		string ans = "None";
		for(auto ch: mp){
			if(ch.second > cur){
				cur = ch.second;
				ans = ch.first;
			}
			else if(ch.second == cur){
				ans = "None";
			}
		}
		cout << s << ": ";

		if(ans == "None"){
			cout << "There is no dominant species" << "\n";
		}
		else if(ans == "B"){
			cout << "The Bobcat is the dominant species" << "\n";
		}
		else if(ans == "C"){
			cout << "The Coyote is the dominant species" << "\n";
		}
		else if(ans == "M"){
			cout << "The Mountain Lion is the dominant species" << "\n";
		}
		else if(ans == "W"){
			cout << "The Wolf is the dominant species" << "\n";
		}
	}

}
