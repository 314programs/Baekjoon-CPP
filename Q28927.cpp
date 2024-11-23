//#include <bits/stdc++.h>
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

	int d[2];

	for(int i = 0; i < 2; i++){
		int a, b, c;
		cin >> a >> b >> c;
		d[i] = a*3 + b*20 + c*120;
	}

	if(d[0] > d[1]) cout << "Max";
	else if(d[0] < d[1]) cout << "Mel";
	else cout << "Draw";

}
