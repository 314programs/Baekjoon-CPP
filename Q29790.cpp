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

	int a, b, c;
	cin >> a >> b >> c;
	if(a >= 1000 && (b >= 8000 || c >= 260)){
		cout << "Very Good";
	}
	else if(a >= 1000){
		cout << "Good";
	}
	else{
		cout << "Bad";
	}

}
