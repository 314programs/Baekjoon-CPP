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

typedef vector<vector<long long>> matrix;
long long mod = 1234567891;
matrix operator *(const matrix &a, const matrix &b){
	int n = a.size();
    matrix ans(n, vector<long long>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans[i][j] = 0;
            for(int k = 0; k < n; k++){
                ans[i][j] += a[i][k] * b[k][j];
            }
            ans[i][j] %= mod;
        }
    }
    return ans;
}
