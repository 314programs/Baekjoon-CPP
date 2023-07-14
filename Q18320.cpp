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

int n, k, m;
bool check(int x){
	int g = 0, k_ = k;
	while(g < n && k_ > 0){
		int y = (n-g)/x;
		if(y < m){
			g += k_ * m;
			break;
		}

		int maxmatch = n - x*y;
		int numdays = (maxmatch-g)/y+1;
		if(numdays > k_) numdays = k_;
		g += y*numdays;
		k_ -= numdays;
	}

	return g >= n;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	cin >> n >> k >> m;
	int left = 1;
	int right = n;
	
	while(left <= right){
		int mid = (left+right)/2;
		if(check(mid)){
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}
	cout << left-1;


}
