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
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        int cur_dif = n;
        int cnt = 1;
        while(true){
            int multi = pow(cnt, m);
            if(abs(multi - n) > cur_dif){
                cnt--;
                break;
            }
            cur_dif = abs(multi-n);
            cnt++;
        }
        cout << cnt << "\n";
    }

}
