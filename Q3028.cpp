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

	vector<int> a(3);
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;

	for(auto ch: s){
		if(ch == 'A'){
			swap(a[0], a[1]);
		}
		else if(ch == 'B'){
			swap(a[1], a[2]);
		}
		else{
			swap(a[0], a[2]);
		}
	}

	for(int i = 0; i < 3; i++){
		if(a[i] == 0){
			cout << i+1;
		}
	}

} 
