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

	int n, range, x, y;
	cin >> n >> range >> x >> y;

	int ans = 0;
	for(int i = 0; i < n; i++){
		int ax, ay;
		cin >> ax >> ay;
		if((ax-x)*(ax-x) + (ay-y)*(ay-y) <= range*range){
			ans++;
		}
	}
	cout << n-ans;


} 
