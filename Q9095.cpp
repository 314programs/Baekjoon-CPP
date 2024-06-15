#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int testcase;
    cin >> testcase;

    while(testcase--){
        int num;
        cin >> num;

        int dp[11];
        memset(dp, 0, sizeof(dp));

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        for(int i = 4; i <= num; i++){
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }

        cout << dp[num] << "\n";
    }
    
}
