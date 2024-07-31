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

    int n;
    cin >> n;
    int cnt = 1;
    while(n != 1){
        if(n%2 == 0){
            n /= 2;
        }
        else{
            n = n*3 + 1;
        }
        cnt++;
    }
    cout << cnt;
}
