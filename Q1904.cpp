//Must practice... DP...

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;

    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int MOD = 15746;

    for(int i = 0; i < n; i++){
        if(i + 1 <= n){
            dp[i+1] = (dp[i]+dp[i+1])%MOD;
        }
        if(i + 2 <= n){
            dp[i+2] = (dp[i]+dp[i+2])%MOD;
        }
    }
    cout << dp[n];

}
