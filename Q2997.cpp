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

	vector<int> a(3);
	for(int i = 0; i < 3; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	int d1 = a[1] - a[0];
	int d2 = a[2] - a[1];
	if(d1 < d2){
		cout << a[1] + d1;
	}
	else if(d1 > d2){
		cout << a[0] + d2;
	}
	else{
		cout << a[2] + d1;
	}
	

}
