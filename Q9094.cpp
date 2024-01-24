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

    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        int cnt = 0;
        for(int i = 1; i < n; i++){
            for(int j = i+1; j < n; j++){
                int top = (i*i + j*j + m);
                int bottom = (i*j);
                if(top%bottom == 0) cnt++;
            }
        }
        cout << cnt << "\n";
    }

}
