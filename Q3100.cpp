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

string format[4][6];

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);


	vector<string> a(6);
	set<char> c;
	for(int i = 0; i < 6; i++){
		cin >> a[i];
		for(auto ch: a[i]){
			c.insert(ch);
		}
	}

	vector<char> check;
	for(auto ch: c){
		check.push_back(ch);	
	}

	int ans = 1e9;
	for(int i = 0; i < check.size(); i++){
		for(int j = 0; j < check.size(); j++){
			if(i == j) continue;
			int temp1 = 0;
			int temp2 = 0;
			string t2 = string(3, check[i]) + string(3, check[j]) + string(3, check[i]);

			for(int y = 0; y < 6; y++){
				for(int x = 0; x < 9; x++){
					if(a[y][x] != check[i] && (y == 0 || y == 1 || y == 4 || y == 5)) temp1++;
					if(a[y][x] != check[j] && (y == 2 || y == 3)) temp1++;
					if(a[y][x] != t2[x]) temp2++;
				}
			}
			ans = min({ans, temp1, temp2});
		}
	}

	for(int i = 0; i < check.size(); i++){
		for(int j = 0; j < check.size(); j++){
			for(int k = 0; k < check.size(); k++){
				if(i == j || j == k || i == k) continue;
				int temp1 = 0;
				int temp2 = 0;
				string t2 = string(3, check[i]) + string(3, check[j]) + string(3, check[k]);

				for(int y = 0; y < 6; y++){
					for(int x = 0; x < 9; x++){
						if(a[y][x] != check[i] && (y == 0 || y == 1)) temp1++;
						if(a[y][x] != check[j] && (y == 2 || y == 3)) temp1++;
						if(a[y][x] != check[k] && (y == 4 || y == 5)) temp1++;
						if(a[y][x] != t2[x]) temp2++;
					}
				}
				ans = min({ans, temp1, temp2});
			}
		}
	}

	if(check.size() == 1) ans = 18;
	cout << ans;

}
