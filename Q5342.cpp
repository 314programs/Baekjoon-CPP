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


	double ans = 0;
	while(true){
		string s;
		cin >> s;

		if(s == "Paper"){
			ans += 57.99;
		}
		else if(s == "Printer"){
			ans += 120.50;
		}
		else if(s == "Planners"){
			ans += 31.25;
		}
		else if(s == "Binders"){
			ans += 22.50;
		}
		else if(s == "Calendar"){
			ans += 10.95;
		}
		else if(s == "Notebooks"){
			ans += 11.20;
		}
		else if(s == "Ink"){
			ans += 66.95;
		}
		else{
			cout << fixed << setprecision(2) << "$" << ans;
			break;
		}
	}
    
}
