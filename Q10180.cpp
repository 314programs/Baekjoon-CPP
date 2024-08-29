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
		int n;
		int d;
		cin >> n >> d;
		int cnt = 0;
		for(int i = 0; i < n; i++){
			float v, f, c;
			cin >> v >> f >> c;
			float travelled = v * (f/c);
			if(travelled >= d) cnt++;
		}
		cout << cnt << "\n";
	}

}
