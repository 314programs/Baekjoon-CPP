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
	while(tc--){
		cout << "Case #" << cnt << ": ";
		double a, b;
		cin >> a >> b;
		cout << (int)(pow(b, (double)1/3)) - (int)(pow(a-1, (double)1/3)) << "\n";
		cnt++;
	}
}
