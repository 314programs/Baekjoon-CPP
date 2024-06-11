//I hate rounding hmm
//I just got this correct through brutal force(looping)
//Checking the short answer out, just use int + (division val-1)/(division val) for rounding

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

	int h, w, i, j;
	cin >> h >> w >> i >> j;
	cout << ((h+i)/(i+1)) * ((w+j)/(j+1));
	

}
