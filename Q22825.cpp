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

        int cur_mx = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i*i*i + j*j*j <= n*n*n){
                    cur_mx = max(cur_mx, i*i*i+j*j*j);
                }
            }
        }
        cout << n*n*n - cur_mx << "\n";
    }
    

}
