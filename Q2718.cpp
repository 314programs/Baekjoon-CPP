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

int f[101];
int g[101];
int h[101];

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	f[0] = 1;
	f[1] = 1;
	g[0] = 0;
	g[1] = 1;
	h[0] = 0;
	h[1] = 1;
	for(int i = 2; i <= 100; i++){
		f[i] = f[i-1] + f[i-2] + g[i-1] + 2 * h[i-1];
		g[i] = f[i-1] + g[i-2];
		h[i] = f[i-1] + h[i-1];
		if(f[i] >= 2147483647){
			break;
		}
	}

	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		cout << f[n] << "\n";
	}

}
