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
	if(n < 4){
		cout << 0;
	}
	else{
		int ans = 0;
		for(int j = 3; j <= n-1; j++){
			for(int k = 2; k <= n-2; k++){
				for(int l = 1; l <= n-3; l++){
					if(n > j && j > k && k > l){
						ans++;
					}
				}
			}
		}
		cout << ans;
	}
	

} 
