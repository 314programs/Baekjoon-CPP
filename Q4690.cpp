//Don't use pow...
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

	for(int cur = 6; cur <= 100; cur++){
		for(int a = 2; a <= 100; a++){
			for(int b = a+1; b <= 100; b++){
				for(int c = b+1; c <= 100; c++){
					if(a*a*a + b*b*b + c*c*c == cur*cur*cur){
						cout << "Cube = " << cur << ", Triple = (" << a << "," << b << "," << c << ")\n";
						break;
					}
				}
			}
		}
	}

}
