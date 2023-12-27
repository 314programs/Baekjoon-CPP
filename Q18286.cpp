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

int is_set(int state, int index){
	//return (int)(state & (1 << index));
	if(state & (1 << index)) return 1;
	else return 0;
}

bool square(int cur_state, int pre_state, int m){
	for(int i = 0; i < m-1; i++){
		int color11 = is_set(cur_state, i);
		int color12 = is_set(cur_state, i+1);
		int color21 = is_set(pre_state, i);
		int color22 = is_set(pre_state, i+1);

		if(color11 == color12 && color11 == color21 && color11 == color22){
			return false;
		}
	}
	return true;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int size = (1 << m);
	vector<vector<int>> ans(size, vector<int>(size));
	vector<vector<int>> a(size, vector<int>(size));
	for(int i = 0; i < size; i++){
		ans[i][i] = 1;
		for(int j = 0; j < size; j++){
			if(square(i, j, m)){
				a[i][j] = 1;
			}
		}
	}

	n--;
	while(n > 0){
		if(n%2 == 1){
			ans = ans * a;
		}
		a = a*a;
		n /= 2;
	}

	int sum = 0;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			sum += ans[i][j];
			sum %= mod;
		}
	}
	cout << sum;


}
