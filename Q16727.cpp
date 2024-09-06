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

	int p1, s1, p2, s2;
	cin >> p1 >> s1 >> s2 >> p2;
	int p = p1 + p2;
	int s = s1 + s2;

	if(p > s){
		cout << "Persepolis";
	}
	else if(s > p){
		cout << "Esteghlal";
	}
	else{
		if(s1 > p2){
			cout << "Esteghlal";
		}
		else if(s1 < p2){
			cout << "Persepolis";
		}
		else{
			cout << "Penalty";
		}
	}
	

}
