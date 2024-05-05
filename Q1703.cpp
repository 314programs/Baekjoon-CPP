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
    
    while(true){
        int tc;
        cin >> tc;
        if(tc == 0) break;

        int ans = 1;
        while(tc--){
            int n, m;
            cin >> n >> m;
            ans *= n;
            ans -= m;
        }
        cout << ans << "\n";
    }

}
