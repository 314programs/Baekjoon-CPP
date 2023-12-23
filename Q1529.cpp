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

bool check(string temp){
	for(auto ch: temp){
		if(ch != '4' && ch != '7'){
			return false;
		}
	}
	return true;
}


int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	int n, l;
	cin >> n >> l;
	
	set<string> s;
	matrix ans = {{1, 0}, {0, 1}};
	matrix a = {{0, 0,}, {0, 0}};

	for(int i = 0; i < n; i++){
		string temp;
		cin >> temp;
		if(s.count(temp)) continue;

		s.insert(temp);
		if(check(temp)){
			if(temp[0] == '4'){
				if(stoi(temp)%10 == 4){
					a[0][0] += 1;
				}
				else{
					a[0][1] += 1;
				}
			}
			else{
				if(stoi(temp)%10 == 4){
					a[1][0] += 1;
				}
				else{
					a[1][1] += 1;
				}
			}
		}

	}

	while(l > 0){
		if(l%2 == 1){
			ans = ans * a;
		}
		a = a*a;
		l /= 2;
	}
	cout << (ans[0][0] + ans[0][1] + ans[1][0] + ans[1][1]) % mod;


}
