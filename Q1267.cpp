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

	int n;
	cin >> n;
	int y = 0;
	int m = 0;
	for(int i = 0; i < n; i++){
		float num;
		cin >> num;
		num++;
		y += ceil(num/30.0) * 10;
		m += ceil(num/60.0) * 15;
	}
	if(y == m){
		cout << "Y M " << y;
	}
	else if(y < m){
		cout << "Y " << y;
	}
	else{
		cout << "M " << m;
	}

}
