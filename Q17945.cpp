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

	int a, b;
	cin >> a >> b;
	int root1 = (-a*2 + sqrt(4*a*a - 4*b))/2;
	int root2 = (-a*2 - sqrt(4*a*a - 4*b))/2;
	if(root1 == root2){
		cout << root1;
	}
	else{
		cout << root2 << " " << root1;
	}
}
