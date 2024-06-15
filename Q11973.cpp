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

int n, k;
bool can(vector<int> &a, int r){
	int cnt = 0;
	int ini = a[0];
	bool rem = false;
	for(auto ch: a){
		if(ch - ini > 2*r){
			cnt++;
			ini = ch;
			rem = false;
		}
		else{
			rem = true;
		}
	}
	cnt++;
	return (bool)(cnt <= k);

}
 
 
int32_t main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);
 
	setIO("");
 
	
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	n = a.size();

	int l = 0, r = (1e9)/2;
	while(l <= r){
		int mid = (l+r)/2;
		if(can(a, mid)){
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	cout << r+1;

 
}
