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
	cin.tie(NULL), std::cout.tie(NULL);
    
    string ans = "S";
	for(int i = 0; i < 8; i++){
        int n;
        cin >> n;
        if(n == 9){
            ans = "F";
        }
    }
    cout << ans;

}
