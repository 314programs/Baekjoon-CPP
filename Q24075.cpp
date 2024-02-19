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

	setIO("");

	int a, b;
	cin >> a >> b;

	vector<int> ans = {a-b, a+b};
	sort(ans.begin(), ans.end(), greater<int>());
	for(auto ch: ans){
		cout << ch << "\n";
	}

}
