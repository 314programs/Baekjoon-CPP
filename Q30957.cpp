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

map<char, int> comp;
bool compare(char &u, char &v){
	return comp[u] < comp[v];
}

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

	comp['B'] = 0;
	comp['S'] = 1;
	comp['A'] = 2;
	
	int n;
	cin >> n;
	string s;
	cin >> s;

	map<char, int> m;
	for(auto ch: s){
		m[ch]++;
	}

	vector<char> ans;
	int max = 0;
	for(auto ch: m){
		if(ch.second == max){
			ans.push_back(ch.first);
		}
		else if(ch.second > max){
			ans.clear();
			ans.push_back(ch.first);
			max = ch.second;
		}
	}
	sort(ans.begin(), ans.end(), compare);

	if(ans.size() == 3){
		cout << "SCU";
	}
	else{
		for(auto ch: ans){
			cout << ch;
		}
	}

}
