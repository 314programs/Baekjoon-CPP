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

    int n, k;
	cin >> n >> k;
	int total = 0;
	int ans = 0;
	while(n--){
		int a, b;
		cin >> a >> b;
		total += a - b;
		ans = max(ans, total-k);
	}
	cout << ans;
	

}
