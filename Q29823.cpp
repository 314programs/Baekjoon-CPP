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
	string s;
	cin >> n >> s;

	int vertical = 0;
	int horizontal = 0;

	for(auto ch: s){
		if(ch == 'N') vertical++;
		else if(ch == 'S') vertical--;
		else if(ch == 'E') horizontal++;
		else horizontal--;
	}
	cout << abs(vertical) + abs(horizontal);
	

}
