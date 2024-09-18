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

	int bx, by, dx, dy;
	cin >> bx >> by >> dx >> dy;
	int fx, fy;
	cin >> fx >> fy;

	int b_x = abs(fx-bx), b_y = abs(fy-by);
	int d_x = abs(fx-dx), d_y = abs(fy-dy);
	int b_m = max(b_x, b_y);
	int d_m = d_x + d_y;

	if(b_m < d_m){
		cout << "bessie";
	}
	else if(b_m == d_m){
		cout << "tie";
	}
	else{
		cout << "daisy";
	}

}
