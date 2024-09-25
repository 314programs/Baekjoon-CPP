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

	int total = n+m;
	for(int w = 1; w < total; w++){
		if(total%w != 0) continue;
		int l = total/w;
		if(l*2 + (w-2)*2 == n && (l-2) * (w-2) == m){
			cout << l << " " << w << "\n";
			break;
		}
	}

} 
