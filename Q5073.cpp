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

	while(true){
		vector<int> a(3);
		for(int i = 0; i < 3; i++){
			cin >> a[i];
		}
		if(a[0] == 0) break;
		sort(a.begin(), a.end());

		if(a[2] >= a[0] + a[1]){
			cout << "Invalid\n";
			continue;
		}

		if(a[0] == a[1] && a[0] == a[2]){
			cout << "Equilateral\n";
		}
		else if(a[0] == a[1] || a[1] == a[2] || a[0] == a[2]){
			cout << "Isosceles\n";
		}
		else{
			cout << "Scalene\n";
		}
	}


}
