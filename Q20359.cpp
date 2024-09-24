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

	int p = 0;
	int cur = 1;
	while(true){
		if(n%cur == 0 && (n/cur)%2 == 1){
			cout << (n/cur) << " " << p;
			break;
		}
		p++;
		cur *= 2;
	}

} 
