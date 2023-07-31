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
const int MOD = 100;

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

matrix power(int n, matrix a){
	if(n == 0){
		return {{1, 0}, {0, 1}};
	}
	else if(n == 1){
		return a;
	}
	else if(n%2 == 0){
		matrix temp = power(n/2, a);
		return temp*temp;
	}
	else{
		return a * power(n-1, a);
	}
}

void print_ans(int ans){
	if(ans < 10) cout << 0;
	cout << ans;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	int x, y, a0, a1, n;
	cin >> x >> y >> a0 >> a1 >> n;

	if(n == 0){
		print_ans(a0);
	}
	else if(n == 1){
		print_ans(a1);
	}
	else{
		matrix multi = {{x, y}, {1, 0}};
		matrix a = power(n-1, multi);
		int ans = (a[0][0] * a1 + a[0][1] * a0)%100;
		print_ans(ans);
	}

}
