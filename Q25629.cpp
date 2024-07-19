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

	int n;
	cin >> n;
	int odd = 0;
	int even = 0;
	
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		if(num%2 == 1) odd++;
		else even++;
	}

	int can = 0;
	if(n%2 == 1){
		if((n/2)+1 == odd && n/2 == even) can = 1;
	}
	else{
		if(odd == even) can = 1;
	}
	cout << can;



}
