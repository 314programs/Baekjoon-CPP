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

	int a;
	string s;
	cin >> a >> s;
	if(s == "miss") cout << 0;
	else if(s == "bad") cout << a * 200;
	else if(s == "cool") cout << a * 400;
	else if(s == "great") cout << a * 600;
	else cout << a * 1000;

}
