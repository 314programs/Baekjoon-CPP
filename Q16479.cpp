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

	float k, d1, d2;
	cin >> k >> d1 >> d2;
	cout << fixed << setprecision(7) << -((d1-d2)/2)*((d1-d2)/2) + k*k;

}
