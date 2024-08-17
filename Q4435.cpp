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

	int n;
	cin >> n;

	vector<int> good = {1, 2, 3, 3, 4, 10};
	vector<int> bad = {1, 2, 2, 2, 3, 5, 10};
	for(int tc = 1; tc <= n; tc++){
		int g = 0;
		for(int i = 0; i < 6; i++){
			int m;
			cin >> m;
			g += m*good[i];
		}

		int b = 0;
		for(int i = 0; i < 7; i++){
			int m;
			cin >> m;
			b += m*bad[i];
		}

		cout << "Battle " << tc << ": ";
		if(g > b){
			cout << "Good triumphs over Evil\n";
		}
		else if(g < b){
			cout << "Evil eradicates all trace of Good\n";
		}
		else{
			cout << "No victor on this battle field\n";
		}

	}
    
}
