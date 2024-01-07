#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

int dp[1001][1001];
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    for(int m = 0; m < n; m++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int i = x1; i < x2; i++){
            dp[i][y1]++;
            dp[i][y2]--;
        }
    }

    int ans = 0;
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
            if(dp[i][j] == k) ans++;
            dp[i][j+1] += dp[i][j];
        }
    }
    cout << ans;
 
}
