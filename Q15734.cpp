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

	int a, b, c;
	cin >> a >> b >> c;

	while(a < b && c > 0){
		a++;
		c--;
	}

	while(b < a && c > 0){
		b++;
		c--;
	}

	if(a != b){
		cout << min(a, b)*2;
	}
	else{
		cout << a*2 + (c/2) * 2;
	}

}
