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

int n, m;
bool can(vector<pair<int, int>> &a, int d){
	int idx = 0;
	int cnt = 0;
	int cur_pos = a[0].first;
	while(idx < m && cnt != n){
		while(idx < m && cur_pos + d > a[idx].second){
			idx++;
		}

		if(cur_pos + d >= a[idx].first && cur_pos + d <= a[idx].second){
			cur_pos += d;
		}
		else if(cur_pos + d < a[idx].first){
			cur_pos = a[idx].first;
		}
		cnt++;
	
	}

	if(cnt != n) return false;
	return true;

}
 
 
int32_t main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);
 
	setIO("");
 
	
	cin >> n >> m;
	vector<pair<int, int>> a(m);
	for(int i = 0; i < m; i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end(), [&](pair<int, int> &u, pair<int, int> &v){
		return u.first < v.first;
	});

	int l = 1, r = 1e18/m;
	while(l <= r){
		int mid = (l+r)/2;
		if(can(a, mid)){
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
	cout << l-1;
 
}
