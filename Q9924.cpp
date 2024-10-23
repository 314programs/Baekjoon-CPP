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

int gcd(int a, int b, int &c){
    if(a == b){
        return b;
    }
    else{
		c++;
        return gcd(max(a,b)-min(a,b), min(a,b), c);
    }
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	int c = 0;
	gcd(a,b,c);
	cout << c;

}
