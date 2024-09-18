#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
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

    int a, d, n;
    cin >> a >> d >> n;

    if((n-a)%d == 0 && (n-a)/d >= 0){
        cout << 1 + (n-a)/d;
    }
    else{
        cout << "X";
    }

}
