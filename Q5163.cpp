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
	const double pi = 3.141592653589793238462643383279;

	while(tc--){
		int ball_cnt;
		double weight;
		cin >> ball_cnt >> weight;
		cout << "Data Set " << cnt << ":\n";

		double helium = 0;
		for(int i = 0; i < ball_cnt; i++){
			double cm;
			cin >> cm;
			helium += cm*cm*cm*pi*((double)4/(double)3000);
		}

		if(helium > weight){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}

		cnt++;
		if(tc > 0){
			cout << "\n";
		}
	}

}
