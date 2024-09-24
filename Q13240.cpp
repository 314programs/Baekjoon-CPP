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

	int h, w;
	cin >> h >> w;
	for(int i = 0; i < h; i++){
		if(i%2 == 0){
			for(int j = 0; j < w; j++){
				if(j%2 == 0) cout << "*";
				else cout << ".";
			}
		}
		else{
			for(int j = 0; j < w; j++){
				if(j%2 == 0) cout << ".";
				else cout << "*";
			}
		}
		if(i != h-1) cout << "\n";
	}


}
