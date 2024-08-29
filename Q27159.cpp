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

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int idx = 0;
	int prev = -1;
	int ans = 0;
	while(idx < n){
		if(prev == -1){
			prev = a[idx];
			ans += prev;
		}
		else{
			if(a[idx]-prev != 1){
				ans += a[idx];
			}
		}
		prev = a[idx];
		idx++;
	}
	cout << ans;

}
