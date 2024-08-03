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

	int tc;
	cin >> tc;
	int cnt = 1;
	while(tc--){
		int a, b;
		cin >> a >> b;
		cout << "Data Set " << cnt++ << ":\n";

		if(a <= b){
			cout << "no drought\n";
		}
		else{
			while(a > b && a > b*5){
				a /= 5;
				cout << "mega ";
			}
			cout << "drought\n";
		}

		cout << "\n";
	}

}
