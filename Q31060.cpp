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

	int n, m, k;
	cin >> n >> m >> k;

	vector<pair<int, int>> pairs(n);
	for(int i = 0; i < n; i++){
		int weight, amount;
		cin >> weight >> amount;
		pairs[i] = {weight, amount};
	}
	sort(pairs.begin(), pairs.end());
	reverse(pairs.begin(), pairs.end());

	deque<pair<int, int>> towers;
	towers.push_back({1e13, m});
	int answer = 0;

	for(auto [w, a]: pairs){
		int remaining = a;
		while(!towers.empty() && remaining > 0 && w + k <= towers.front().first){
			if(towers.front().second > remaining){
				towers.front().second -= remaining;
				remaining = 0;
			}
			else{
				remaining -= towers.front().second;
				towers.pop_front();
			}
		}
		
		int cnt = a - remaining;
		if(cnt > 0){
			towers.push_back({w, cnt});
			answer += cnt;
		}
	}
	cout << answer;


}
