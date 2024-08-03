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

	int x, y, n;
	cin >> x >> y >> n;
	for(int i = 1; i <= n; i++){
		if(i%x == 0 && i%y == 0){
			cout << "FizzBuzz\n";
		}
		else if(i%x == 0){
			cout << "Fizz\n";
		}
		else if(i%y == 0){
			cout << "Buzz\n";
		}
		else{
			cout << i << "\n";
		}
	}
	
}
