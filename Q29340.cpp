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

    vector<string> a(2);
    cin >> a[0] >> a[1];

    int n = a[0].length();
    for(int i = 0; i < n; i++){
        if(a[0][i] >= a[1][i]){
            cout << a[0][i];
        }
        else{
            cout  << a[1][i];
        }
    } 
}
