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

	int n, m;
	cin >> n >> m;
	float ans = 0;
	for(int i = 0; i < m; i++){
		float num;
		cin >> num;
		ans += num;
	}
	cout << fixed << setprecision(5) << (ans + (n-m) * -3)/n << " " <<  (ans + (n-m) * 3)/n;

}
