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
 
int can(vector<int> &a, int k, int n){
	priority_queue<int, vector<int>, greater<int>> cows;
	int mx = 0;

	for(int i = 0; i < k; i++){
		cows.push(a[i]);
		mx = max(a[i], mx);
	}
	for(int i = k; i < n; i++){
		int temp = cows.top() + a[i];
		cows.pop();
		cows.push(temp);
		mx = max(mx, temp);
	}
	return mx;

}
 
int32_t main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);
 
	setIO("");
 
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int l = 1, r = n;
	int ans = -1;
	while(l <= r){
		int mid = (l+r)/2;
		int cur_t = can(a, mid, n);
		if(cur_t <= k){
			r = mid-1;
			ans = mid;
		}
		else{
			l = mid+1;
		}
	}
	cout << ans;
 
}
