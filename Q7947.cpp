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
		int r = 0, g = 0, b = 0;
		for(int i = 0; i < 10; i++){
			int d, e, f;
			cin >> d >> e >> f;
			r += d;
			g += e;
			b += f;
		}

		if(r%10 >= 5){
			r += 10;
		}
		if(g%10 >= 5){
			g += 10;
		}
		if(b%10 >= 5){
			b += 10;
		}
		cout << r/10 << " " << g/10 << " " << b/10 << "\n";
	}

} 
