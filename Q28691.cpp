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

	string s;
	cin >> s;
	if(s == "M"){
		cout << "MatKor";
	}
	else if(s == "W"){
		cout << "WiCys";
	}
	else if(s == "C"){
		cout << "CyKor";
	}
	else if(s == "A"){
		cout << "AlKor";
	}
	else{
		cout << "$clear";
	}
}
