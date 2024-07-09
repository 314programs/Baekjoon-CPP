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

    vector<int> a = {1, 5, 10, 20, 50, 100};
    int mx = -1;
    int val = -1;

    for(int i = 0; i < 6; i++){
        int n;
        cin >> n;
        int cur = n * a[i];
        
        if(cur >= mx){
            mx = cur;
            val = a[i];
        }
    }
    cout << val;

}
