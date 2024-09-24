//Not a good question...

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int cnt = 1;

    while(true){
        int n;
        cin >> n;
        if(n == 0) break;

        vector<float> a(n+1, 0);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        cout << "Case " << cnt++ << ": ";

        if(n%2 == 0){
            cout << fixed << setprecision(1) << (a[n/2] + a[(n/2)+1])/2 << "\n"; 
        }
        else{
            cout << fixed << setprecision(1) << a[(n+1)/2] << "\n";
        }

    }

}
