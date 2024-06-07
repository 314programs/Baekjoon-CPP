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
        int sides = 0;
        for(int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            sides += b/2;
        }
        cout << sides/2 << "\n";
    }

}
