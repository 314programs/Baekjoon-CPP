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

	int a[101];
	memset(a, 0, sizeof(a));

	int ans = 0;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		if(a[num] == 0){
			a[num] = 1;
			ans++;
		}
	}

	cout << n-ans;

} 
