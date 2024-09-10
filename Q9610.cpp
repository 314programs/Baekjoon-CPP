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
	cin.tie(NULL), std::cout.tie(NULL);
 
    int n;
    cin >> n;

    int q1 = 0, q2 = 0, q3 = 0, q4 = 0, axis = 0;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(x == 0 || y == 0){
            axis++;
        }

        if(x > 0 && y > 0) q1++;
        if(x < 0 && y > 0) q2++;
        if(x < 0 && y < 0) q3++;
        if(x > 0 && y < 0) q4++;
    }

    cout << "Q1: " << q1 << "\n";
    cout << "Q2: " << q2 << "\n";
    cout << "Q3: " << q3 << "\n";
    cout << "Q4: " << q4 << "\n";
    cout << "AXIS: " << axis << "\n";


}
