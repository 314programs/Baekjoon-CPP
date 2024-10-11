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

	bool w = false;
	bool g = false;
	bool b = false;

	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 15; j++){
			char c;
			cin >> c;
			if(c == 'w') w = true;
			if(c == 'g') g = true;
			if(c == 'b') b = true;
		}
	}

	if(w){
		cout << "chunbae";
	}
	else if(g){
		cout << "yeongcheol";
	}
	else{
		cout << "nabi";
	}

}
