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
        
        int rem = n-m;
        int two = 0, three = 0;

        if(rem >= 2){
            if(rem%2 == 0){
                two += rem/2;
            }
            else{
                three++;
                rem -= 3;
                if(rem > 0) two += rem/2;
            }
        }
        cout << two << " " << three << "\n";
    }
}
