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
 
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int> a(n);
        double total = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            total += a[i];
        }

        total /= n;
        double cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > total){
                cnt++;
            }
        }
        double ans = ((cnt/n)*100000);
        cout << fixed << setprecision(3) << floor(ans+0.5)/1000 << "%\n";

    }
}
