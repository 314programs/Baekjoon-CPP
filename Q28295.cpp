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

	int cur = 0;
	for(int i = 0; i < 10; i++){
		int n;
		cin >> n;

		if(n == 1){
			cur += 90;
		}
		else if(n == 2){
			cur += 180;
		}
		else{
			cur -= 90;
		}
		cur = (cur + 360)%360;
	}

	if(cur == 0){
		cout << "N";
	}
	else if(cur == 90){
		cout << "E";
	}
	else if(cur == 180){
		cout << "S";
	}
	else{
		cout << "W";
	}
    
}
