//I don't think this needed DP

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;

    int ans = -1;
    for(int i = 0; i*5 <= n; i++){
        if((n - i*5)%2 == 0){
            ans = i + ((n - i*5)/2);
        }
    }
    cout << ans;

}
