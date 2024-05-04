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

        int even = 0, odd = 0;
        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            if(m%2 == 0) even += m;
            else odd += m;
        }

        if(even > odd){
            cout << "EVEN\n";
        }
        else if(even < odd){
            cout << "ODD\n";
        }
        else{
            cout << "TIE\n";
        }

    }

}
