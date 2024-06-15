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

	if(n == 1){
		cout << 1;
	}
	else{
		int diff = n/2;
		for(int i = diff; i <= n; i += diff){
			cout << i << " ";
		}
		for(int r = diff; r > 0; r--){
			int multi = 0;
			while(r < diff){
				int cur = r + multi * diff;
				if(cur > n) break;
				if(cur > 0) cout << cur << " ";
				multi++;
			}
		}
	}

}
