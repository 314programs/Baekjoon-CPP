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

	int w, n, tc;
	cin >> w >> n >> tc;
	int temp = tc;
	int ans = 0;
	while(tc--){
		int num;
		cin >> num;
		if(num < w || num > n){
			ans++;
		}
	}
	cout << temp-ans;

}
