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
		ans[i][j] %= mod;
            }
        }
    }
    return ans;
}


int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	//Power, matrix size
	int p, m;
	cin >> p >> m;

	vector<vector<int>> ans(m, vector<int>(m));
	vector<vector<int>> a(m, vector<int>(m));

	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(i == j) ans[i][j] = 1;
		}
	}

	while(p > 0){
		if(p%2 == 1){
			ans = ans * a;
		}
		a = a*a;
		p /= 2;
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

}
