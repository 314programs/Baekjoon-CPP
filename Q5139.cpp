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

	int tc;
	cin >> tc;
	int cnt = 1;
	int n = tc;

	while(tc--){
		int h, w;
		cin >> h >> w;
		vector<string> a(h);

		cout << "Data Set " << cnt << ":\n";

		for(int i = 0; i < h; i++){
			cin >> a[i];
		}

		for(int i = 0; i < w; i++){
			int ans = 0;
			bool found = false;
			for(int j = 0; j < h; j++){
				if(a[j][i] == 'X'){
					found = true;
					break;
				}
				else if(a[j][i] == 'S'){
					ans++;
				}
				else{
					ans += 3;
				}
			}

			if(!found){
				cout << "N ";
			}
			else{
				cout << ans << " ";
			}
		}
		if(n == cnt) cout << "\n";
		else cout << "\n\n";
		cnt++;
	}

} 
