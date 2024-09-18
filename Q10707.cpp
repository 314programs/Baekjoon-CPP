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

	int X, Y_d, Y_limit, Y_add, L;
	cin >> X >> Y_d >> Y_limit >> Y_add >> L;

	int Y = Y_d;
	if(L > Y_limit) Y += (L - Y_limit) * Y_add;
	cout << min(Y, X*L);

}
