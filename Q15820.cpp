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

	int n, m;
	cin >> n >> m;
	bool test = true;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		if(a != b) test = false;
	}
	bool system = true;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		if(a != b) system = false;
	}

	if(!test){
		cout << "Wrong Answer";
	}
	else if(test && system){
		cout << "Accepted";
	}
	else if(test && !system){
		cout << "Why Wrong!!!";
	}

}
