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

	int n;
	string s;
	cin >> n >> s;

	int len = s.length();
	int row = len/n;
	char a[row][n];
	int cnt = 0;

	for(int i = 0; i < row; i++){
		if(i%2 == 0){
			for(int j = 0; j < n; j++){
				a[i][j] = s[cnt++];
			}
		}
		else{
			for(int j = n-1; j >= 0; j--){
				a[i][j] = s[cnt++];
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < row; j++){
			cout << a[j][i];
		}
	}

}
