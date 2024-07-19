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
	for(int i = 1; i <= n; i++){
		if(i%7 == 0 && i%11 != 0){
			cout << "Hurra!";
		}
		else if(i%7 != 0 && i%11 == 0){
			cout << "Super!";
		}
		else if(i%7 == 0 && i%11 == 0){
			cout << "Wiwat!";
		}
		else{
			cout << i;
		}
		cout << "\n";
	}
    
}
