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
	vector<int> a(n+1, 0);
	for(int i = 0; i < m; i++){
		int c, d;
		cin >> c >> d;
		a[c]++;
		a[d]++;
	}

	for(int i = 1; i <= n; i++){
		cout << a[i] << "\n";
	}

}
