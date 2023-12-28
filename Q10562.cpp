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
long long mod = 1000000009;
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

int knight[4][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}};

int chess_check(vector<int> a, int m, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < 4; k++){
				if(!(a[i] & (1 << j))) continue;

				int new_x = i + knight[k][0];
				int new_y = j + knight[k][1];
				if(new_x >= 0 && new_x < 3 && new_y >= 0 && new_y < m && (a[new_x] & (1 << new_y))){
					return false;
				}
			}
		}
	}
	return true;
}



int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> m >> n;

		if(n == m & n == 1){
			cout << 2 << "\n";
			continue;
		}
		else if(n == 1) swap(n, m);
		else if(n == 2){
			int ans = 0;
			int size = (1 << m);
			for(int i = 0; i < size; i++){
				for(int j = 0; j < size; j++){
					vector<int> temp = {i, j};
					if(chess_check(temp, m, 2)){
						ans++;
					}
				}
			}
			cout << ans << "\n";
			continue;
		}
		int size = 1 << (m*2);

		matrix a(size, vector<int>(size));
		matrix ans(size, vector<int>(size));

		//Prev
		for(int i = 0; i < size; i++){
			ans[i][i] = 1;
			//Cur
			for(int j = 0; j < size; j++){
				vector<int> temp(3);
				temp[1] = i >> m;
				temp[2] = j >> m;
				temp[0] = 0;
				for(int k = 0; k < m; k++){
					if(i & (1 << k)){
						temp[0] += (int)(1 << k);
					}
				}

				int j_fir = 0;
				for(int k = 0; k < m; k++){
					if(j & (1 << k)){
						j_fir += (int)(1 << k);
					}
				}

				if(j_fir != temp[1]) continue;
				if(chess_check(temp, m, 3)){
					a[i][j] = 1;
				}
			}
		}

		n -= 2;
		n = max((int)0, n);
		while(n > 0){
			if(n%2 == 1){
				ans = a * ans;
			}
			n /= 2;
			a = a*a;
		}

		int sum = 0;
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				sum += ans[i][j];
				sum %= mod;
			}
		}
		cout << sum << "\n";


	}

}
