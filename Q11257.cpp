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
	while(tc--){
		string s;
		double a, b, c;
		cin >> s >> a >> b >> c;
		int total = a+b+c;
		cout << s << " " << total;

		if(total >= 55 && 35*0.3 <= a && 25*0.3 <= b && 40*0.3 <= c){
			cout << " PASS\n";
		}
		else{
			cout << " FAIL\n";
		}
	}

}
