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

    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int fin = 0;
        int cur = i;
        while(cur != 0){
            fin += cur%10;
            cur /= 10;
        }
        if(i%fin == 0) cnt++;
    }
    cout << cnt;

}
