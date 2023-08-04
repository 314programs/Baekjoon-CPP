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

//0: Min, 1: Max
set<int> DP[1 << 6];
int n;
vector<int> a;

bool is_prime(int num){
	if(num <= 1) return false;
	if(num < 2){
		return true;
	}

	for(int i = 2; i*i <= num; i++){
		if(num%i == 0){
			return false;
		}
	}
	return true;
}

set<int> solve(int state){
	set<int> &ans = DP[state];
	if(ans.size() > 0){
		return ans;
	}
	if(state == 0){
		return ans;
	}

	for(int i = 0; i < (1 << n); i++){
		int first = i & state;
		int second = (~first) & state;
		if(first == 0 || second == 0){
			continue;
		}
		solve(first);
		solve(second);

		for(int x: DP[first]){
			for(int y: DP[second]){
				if(x != 0){
					ans.insert(y/x);
				}
				if(y != 0){
					ans.insert(x/y);
				}

				ans.insert(x+y);
				ans.insert(x*y);
				ans.insert(x-y);
				ans.insert(y-x);
			}
		}
	}
	return ans;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	cin >> n;

	a.resize(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		DP[1 << i].insert(a[i]);
	}

	set<int> ans = solve((1 << n)-1);

	int mn = 1e12, mx = -1e12;
	for(int x: ans){
		if(is_prime(x)){
			mn = min(mn, x);
			mx = max(mx, x);
		}
	}
	if(mn == 1e12){
		cout << -1;
	}
	else{
		cout << mn << "\n" << mx;
	}

}
