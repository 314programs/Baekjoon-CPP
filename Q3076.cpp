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

	int hm, wm;
	cin >> hm >> wm;
	char cur = 'X';

	for(int i = 0; i < h; i++){
		for(int h_ = 0; h_ < hm; h_++){
			if(i%2 == 0) cur = 'X';
			else cur = '.';
			for(int j = 0; j < w; j++){

				for(int w_ = 0; w_ < wm; w_++){
					cout << cur;
				}
				if(cur == 'X') cur = '.';
				else cur = 'X';
			}
			cout << "\n";
		}
	}
	
} 
