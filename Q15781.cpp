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


int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	setIO("");

	int n, m;
	cin >> n >> m;

	int n_max = 0, m_max = 0;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		n_max = max(n_max, num);
	}
	for(int i = 0; i < m; i++){
		int num;
		cin >> num;
		m_max = max(m_max, num);
	}
	cout << n_max + m_max;

}
