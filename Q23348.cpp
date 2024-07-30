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

	int a, b, c;
	cin >> a >> b >> c;

	int tc;
	cin >> tc;
	int ans = 0;

	while(tc--){
		int cur = 0;
		for(int i = 0; i < 3; i++){
			int x, y, z;
			cin >> x >> y >> z;
			cur += x*a + y*b + z*c;
		}
		ans = max(cur, ans);
	}
	cout << ans;

}
