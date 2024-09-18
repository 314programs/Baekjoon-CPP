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
	while(n--){
		string s;
		cin >> s;
		if(s == "Algorithm"){
			cout << "204\n";
		}
		else if(s == "DataAnalysis"){
			cout << "207\n";
		}
		else if(s == "ArtificialIntelligence"){
			cout << "302\n";
		}
		else if(s == "CyberSecurity"){
			cout << "B101\n";
		}
		else if(s == "Network"){
			cout << "303\n";
		}
		else if(s == "Startup"){
			cout << "501\n";
		}
		else if(s == "TestStrategy"){
			cout << "105\n";
		}
	}
	
}
