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

int DP[100005][11][2][2];
int n, k;

//Number of questions A solved, 
int solve(int idx, int A, int B, int C){
	if(idx > n){
		if(A == 0 && C == 1){
			return 1;
		}
		else{
			return 0;
		}
	}

	int &ans = DP[idx][A][B][C];
	if(ans != -1) return ans;
	ans = 0;

	if(k > 0) ans += solve(idx+1, (A+1)%k, 0, C);
	if(B == 0){
		ans += solve(idx+1, A, 1, C);
	}
	ans += solve(idx+1, A, 0, 1);
	ans %= mod;
	return ans;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	cin >> n >> k;
	memset(DP, -1, sizeof(DP));
	cout << solve(1, 0, 0, 0);

}
