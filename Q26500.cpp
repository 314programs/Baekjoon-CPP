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

struct cow{
	int weight, x, direction;
};

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	setIO("");

	int n;
	cin >> n;

	while(n--){
		double a, b;
		cin >> a >> b;
		cout << fixed << setprecision(1) << abs(a-b) << "\n";
	}

}
