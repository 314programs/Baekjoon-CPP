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

	int tc;
	cin >> tc;
	while(tc--){
		int d, e, f;
		cin >> d >> e >> f;
		e--; f--;
		if(d == 1){
			for(int i = e; i <= f; i++){
				a[i] = (a[i]*a[i])%2010;
			}
		}
		else{
			int ans = 0;
			for(int i = e; i <= f; i++){
				ans += a[i];
			}
			cout << ans << "\n";
		}
	}
	

}
