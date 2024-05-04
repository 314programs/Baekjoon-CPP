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

	vector<int> a(20);
	for(int i = 0; i < 20; i++){
		a[i] = i+1;
	}

	for(int i = 0; i < 10; i++){
		int s, e;
		cin >> s >> e;
		reverse(a.begin()+s-1, a.begin()+e);
	}

	for(int i = 0; i < 20; i++){
		cout << a[i] << " ";
	}

}
