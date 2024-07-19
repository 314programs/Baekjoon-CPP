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
	cin.tie(NULL), std::cout.tie(NULL);

	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >> a >> b;

		int cnt = 0;
		for(int i = 0; i <= 16; i++){
			if(a & (1 << i)){
				cnt++;
			}
		}
		if(cnt%2 == b){
			cout << "Valid\n";
		}
		else{
			cout << "Corrupt\n";
		}
	}

    
}
