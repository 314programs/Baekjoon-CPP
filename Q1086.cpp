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

int DP[1 << 15][100];

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	int n;
	cin >> n;

	vector<string> a(n);
	vector<int> num(n);
	vector<int> len(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		len[i] = a[i].size();
	}

	int k;
	cin >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < len[i]; j++){
			num[i] = num[i] * 10 + (a[i][j] - '0');
			num[i] %= k;
		}
	}

	vector<int> ten(51);
	ten[0] = 1%k;
	for(int i = 1; i <= 50; i++){
		ten[i] = (ten[i-1] * 10) % k;
	}

	DP[0][0] = 1;
	for(int state = 0; state < (1 << n); state++){
		for(int i = 0; i < k; i++){
			for(int j = 0; j < n; j++){
				if(state & (1 << j)) continue;
				int next = (i * ten[len[j]]) + num[j];
				next %= k;
				DP[state | (1 << j)][next] += DP[state][i];
			}
		}
	}

	int final = DP[(1 << n) - 1][0];
	int div = 1;
	for(int i = 1; i <= n; i++){
		div *= i;
	}
	int g = gcd(final, div);
	cout << final/g << "/" << div/g;

}
