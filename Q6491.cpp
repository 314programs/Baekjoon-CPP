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

    while(true){
        int n;
        cin >> n;
        if(n == 0) break;

        int total = 0;
        for(int i = 1; i < n; i++){
            if(n%i == 0) total += i;
        }

        cout << n << " ";
        if(total < n){
            cout << "DEFICIENT\n";
        }
        else if(total > n){
            cout << "ABUNDANT\n";
        }
        else{
            cout << "PERFECT\n";
        }
    }

}
