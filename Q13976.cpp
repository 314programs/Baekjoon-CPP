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

typedef vector<vector<int>> matrix;
const int MOD = 1000000007;

matrix operator * (const matrix &a, const matrix &b){
	int n =  a.size();
	matrix c (n, vector<int> (n));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= MOD;
		}
	}
	return c;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	int n;
	cin >> n;

	if(n%2 == 1){
		cout << 0;
	}
	else{
		matrix ans (8, vector<int>(8));
		matrix a (8, vector<int>(8));
		for(int i = 0; i < 8; i++){
			ans[i][i] = 1;
		}

		a[0][7] = 1;
		a[1][6] = 1;
		a[2][5] = 1;
		a[4][3] = 1;
		a[3][4] = a[3][7] = 1;
		a[6][1] = a[6][7] = 1;
		a[5][2] = 1;
		a[7][0] = a[7][3] = a[7][6] = 1;

		while(n > 0){
			if(n%2 == 1){
				ans = ans*a;
			}
			a = a*a;
			n /= 2;
		}

		int sum = 0;
		for(int i = 0; i < 7; i++){
			sum += ans[0][i];
		}
		cout << sum%MOD;
	}

}
