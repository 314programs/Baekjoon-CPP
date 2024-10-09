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

	vector<int> ans = {1,2,3,4,5,1,2,3,4,5};
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int remark = true;
		for(int j = 0; j < 10; j++){
			int num;
			cin >> num;
			if(num != ans[j]){
				remark = false;
			}
		}
		if(remark) cout << i << "\n";
	}

} 
