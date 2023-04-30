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

	int n;
	cin >> n;
	vector<int> a(n);
	set<int> s;
	vector<int> b;

	for(int i = 0; i < n; i++){
		cin >> a[i];
		s.insert(a[i]);
	}
	sort(a.begin(), a.end());

	for(int i = 1; i <= n*2; i++){
		if(s.count(i) == 0){
			b.push_back(i);
		}
	}

	int i = 0, j = 0;
	int ans = 0;
	while(i < n && j < n){
		if(a[i] < b[j]){
			ans++;
			i++;
		}
		j++;
	}
	cout << ans;

}
