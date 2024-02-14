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

	float a, b, c, d;
	cin >> a >> b >> c >> d;

	float rot1 = a/c + b/d;
	float rot2 = c/d + a/b;
	float rot3 = d/b + c/a;
	float rot4 = b/a + d/c;

	if(max({rot1, rot2, rot3, rot4}) == rot1){
		cout << 0;
	}
	else if(max({rot1, rot2, rot3, rot4}) == rot2){
		cout << 1;
	}
	else if(max({rot1, rot2, rot3, rot4}) == rot3){
		cout << 2;
	}
	else{
		cout << 3;
	}

}
