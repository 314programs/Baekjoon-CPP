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

	int t, n;
	cin >> t >> n;
	int total = 0;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		total += num;
	}
	if(total >= t){
		cout << "Padaeng_i Happy";
	}
	else{
		cout << "Padaeng_i Cry";
	}

}
