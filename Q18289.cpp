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
long long mod = 1000000007;
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

int state_map[10][2][2];

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	int size_k = max(k, (int)1);
	int state_num = 0;

	for(int a = 0; a < size_k; a++){
		for(int b = 0; b < 2; b++){
			for(int c = 0; c < 2; c++){
				state_map[a][b][c] = state_num++;
			}
		}
	}
	int size = size_k * 2 * 2;

	matrix ans(size, vector<int>(size));
	matrix multi(size, vector<int>(size));
	for(int i = 0; i < size; i++){
		ans[i][i] = 1;
	}

	for(int a = 0; a < size_k; a++){
		for(int b = 0; b < 2; b++){
			for(int c = 0; c < 2; c++){
				int state = state_map[a][b][c];
				if(k > 0){
					multi[state][state_map[(a+1)%k][0][c]]++;
				}
				if(b == 0){
					multi[state][state_map[a][1][c]]++;
				}
				multi[state][state_map[a][0][1]]++;
			}
		}
	}

	while(n > 0){
		if(n%2 == 1){
			ans = multi * ans;
		}
		multi = multi * multi;
		n /= 2;
	}
	cout << (ans[0][state_map[0][0][1]] + ans[0][state_map[0][1][1]])%mod;


}
