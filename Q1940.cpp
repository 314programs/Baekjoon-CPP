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

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	int ans = 0;
	int start = 0;
	int end = n-1;

	while(start < end){
		if(a[start] + a[end] == k){
			ans++;
			end--;
			start++;
		}
		else if(a[start] + a[end] > k){
			end--;
		}
		else{
			start++;
		}
	}
	cout << ans;
    
    
}
