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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    for(int i = 0; i < 3; i++){
        int n;
        cin >> n;
        int ans = 0;
        if(n%(a+b) <= a && n%(a+b) > 0){
            ans++;
        }
        if(n%(c+d) <= c && n%(c+d) > 0){
            ans++;
        }
        cout << ans << "\n";
    }

}
