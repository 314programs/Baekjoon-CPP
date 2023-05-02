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

	setIO("helpcross");

	int n, m;
	cin >> n >> m;

	vector<int> chicken(n);
	for(int i = 0; i < n; i++){
		cin >> chicken[i];
	}
	sort(chicken.begin(), chicken.end());

	vector<pair<int, int>> cow(m);
	for(int i = 0; i < m; i++){
		cin >> cow[i].first >> cow[i].second;
	}
	sort(cow.begin(), cow.end());

	int ans = 0, idx = 0;
	priority_queue<int, vector<int>, greater<int>> av_cows;
	for(auto c: chicken){
		while(idx < m && cow[idx].first <= c){
			av_cows.push(cow[idx].second);
			idx++;
		}
		while(!av_cows.empty() && av_cows.top() < c){
			av_cows.pop();
		}

		if(!av_cows.empty()){
			ans++;
			av_cows.pop();
		}
	}

	cout << ans;

}
