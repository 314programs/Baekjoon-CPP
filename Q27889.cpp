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
    cin.tie(NULL), cout.tie(NULL);

	string s;
	cin >> s;

	if(s == "NLCS"){
		cout << "North London Collegiate School";
	}
	else if(s == "BHA"){
		cout << "Branksome Hall Asia";
	}
	else if(s == "KIS"){
		cout << "Korea International School";
	}
	else if(s == "SJA"){
		cout << "St. Johnsbury Academy";
	}

}
