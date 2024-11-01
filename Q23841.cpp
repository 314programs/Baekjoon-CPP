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

	int h, w;
	cin >> h >> w;

	vector<string> a(h);
	for(int i = 0; i < h; i++){
		cin >> a[i];
	}

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w/2; j++){
			if(a[i][w-j-1] == '.' && a[i][j] != '.'){
				a[i][w-j-1] = a[i][j];
			}
			else if(a[i][w-j-1] != '.' && a[i][j] == '.'){
				a[i][j] = a[i][w-j-1];
			}
		}
	}
	for(int i = 0; i < h; i++){
		cout << a[i] << "\n";
	}

}
