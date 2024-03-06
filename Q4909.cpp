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
        float total = 0;
        vector<float> a(6);
        for(int i = 0; i < 6; i++){
            cin >> a[i];
            total += a[i];
        }
        if(total == 0) break;

        total = 0;
        sort(a.begin(), a.end());
        for(int i = 1; i <= 4; i++){
            total += a[i];
        }
        cout << total/4 << "\n";
    }

}
