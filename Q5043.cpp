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

	int n, b;
	cin >> n >> b;
	int cnt = 0;
	while(n > 0){
		n >>= 1;
		cnt++;
	}
	if(b + 1 >= cnt){
		cout << "yes";
	}
	else{
		cout << "no";
	}

}
