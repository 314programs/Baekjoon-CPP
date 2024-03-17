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

	int a, b;
	cin >> a >> b;

	int cur = 0;
	for(int i = 1; i <= a; i++){
		cur += i;
	}

	int ans = cur;
	for(int i = a+1; i <= b; i++){
		cur += i;
		ans *= cur;
		ans %= 14579;
	}
	cout << ans;

}
