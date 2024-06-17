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

int unsurprising(int n){
	return ceil(n/3.0);
}

int surprising(int n){
	return ceil((n-1)/3.0) + 1;
}

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

	int tc;
	cin >> tc;
	int cnt = 1;
	while(tc--){
		int n, s, m;
		cin >> n >> s >> m;
		int ans = 0;
		
		for(int i = 0; i < n; i++){
			int num;
			cin >> num;

			if(unsurprising(num) >= m){
				ans++;
			}
			else if(num >= 2 && num <= 28 && m > unsurprising(num) && m <= surprising(num)){
				if(s > 0){
					s--;
					ans++;
				}
			}
		}
		cout << "Case #" << cnt++ << ": " << ans << "\n";
	}

}
