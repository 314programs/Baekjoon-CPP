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

	while(true){
		int n;
		cin >> n;
		if(n == 0) break;

		vector<pair<string, string>> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i].first;

			a[i].second = a[i].first;
			for(auto &ch: a[i].second){
				ch = tolower(ch);
			}
		}
		sort(a.begin(), a.end(), compare);
		cout << a[0].first << "\n";
	}


} 
