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
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        bool good = true;
        for(int i = 0; i < n-1; i++){
            if(a[i]*2 > a[i+1]){
                good = false;
            }
        }

        cout << "Denominations: ";
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << "\n";

        if(good){
            cout << "Good coin denominations!\n";
        }
        else{
            cout << "Bad coin denominations!\n";
        }
        if(tc != 0) cout << "\n";
    }

}
