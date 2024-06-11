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

	vector<int> a[2];
	int ans[2];

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 10; j++){
			int n;
			cin >> n;
			a[i].push_back(n);
		}
		sort(a[i].begin(), a[i].end());
		ans[i] = a[i][7] + a[i][8] + a[i][9];
	}
	cout << ans[0] << " " << ans[1];

}
