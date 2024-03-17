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

	int tc;
	cin >> tc;
	while(tc--){
		int a, b, c, d;
		int e, f, g, h;
		cin >> a >> b >> c >> d >> e >> f >> g >> h;
		a += e;
		b += f;
		c += g;
		d += h;

		if(a < 1) a = 1;
		if(b < 1) b = 1;
		if(c < 0) c = 0;
		
		cout << a + b*5 + 2*(c+d) << "\n";
	}

}
