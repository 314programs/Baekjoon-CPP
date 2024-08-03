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
	double cost;
	cin >> n >> cost;
	double area = 0, bed_area = 0;
	double no_balcony = 0, balcony = 0;

	while(n--){
		int a;
		string s;
		cin >> a >> s;
		area += a;

		if(s == "bedroom"){
			bed_area += a;
		}

		if(s != "balcony"){
			no_balcony += a;
		}
		else{
			balcony += a;
		}
	}
	cout << area << "\n" << bed_area << "\n";
	cout << fixed << setprecision(6) << (no_balcony + (balcony*0.5f))*cost;

	
}
