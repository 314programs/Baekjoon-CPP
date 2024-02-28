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

	for(int i = 1; i <= n; i++){
		cout << "Scenario #" << i << ":\n";
		vector<int> a(3);
		for(int j = 0; j < 3; j++){
			cin >> a[j];
		}
		sort(a.begin(), a.end());

		if((a[0]*a[0]) + (a[1]*a[1]) == a[2]*a[2]){
			cout << "yes\n\n";
		}
		else{
			cout << "no\n\n";
		}
	}

}
