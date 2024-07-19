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
	vector<string> a(n);
	vector<string> b(m);

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << a[i] << " as " << b[j] << "\n";
		}
	}

}
