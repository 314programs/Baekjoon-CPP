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

	int n, k, p;
	cin >> n >> k >> p;

	int ans = 0;
	for(int i = 0; i < n; i++){
		int cnt = 0;
		for(int j = 0; j < k; j++){
			int num;
			cin >> num;
			if(num == 0) cnt++;
		}
		if(cnt < p) ans++;
	}
	cout << ans;

}
