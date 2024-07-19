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

	int total = 0;
	while(m--){
		float cur;
		cin >> cur;
		total += round(cur/2);
	}
	
	if(n > total) cout << "NO";
	else cout << "YES";

}
