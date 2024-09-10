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
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		if(i == 0) a[i] = num;
		else{
			a[i] = a[i-1] + num;
		}
	}

	while(m--){
		int cur;
		cin >> cur;

		for(int i = 0; i < n; i++){
			if(a[i] > cur){
				cout << i+1 << "\n";
				break;
			}
		}
	}


}
