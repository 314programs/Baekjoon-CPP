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

	while(true){
		int l, h, w, v;
		cin >> l >> h >> w >> v;

		if(l == 0 && h == 0) break;

		if(l == 0){
			l = v/(h*w);
		}
		else if(h == 0){
			h = v/(l*w);
		}
		else if(w == 0){
			w = v/(l*h);
		}
		else{
			v = l * h * w;
		}
		cout << l << " " << h << " " << w << " " << v << '\n';

	}

}
