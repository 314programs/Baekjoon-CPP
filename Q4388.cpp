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
        int a, b;
        cin >> a >> b;
        int add = 0;
        int cnt = 0;
        if(a == 0 && b == 0) break;

        while(a || b){
            add += a%10;
            add += b%10;
            if(add > 9) cnt++;

            add /= 10;
            a /= 10;
            b /= 10;
        }
        cout << cnt << "\n";
    }

}
