#include <bits/stdc++.h>
using namespace std;
#define ll long long 

//Number, number of numbers needed to make said number
ll dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int tc;
    cin >> tc;

    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;

    dp[2][1] = 1;
    dp[2][2] = 1;

    dp[3][1] = 1;
    dp[3][2] = 2;
    dp[3][3] = 1;
    
    //I accidently put this inside while loop oops
    for(int i = 4; i <= 1000; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] += dp[i-1][j-1] + dp[i-2][j-1] + dp[i-3][j-1];
            dp[i][j] %= 1000000009;
        }
    }

    while(tc--){
        int n, m;
        cin >> n >> m;

        cout << dp[n][m] << "\n";

    }

}
