//Solved it by DP but there is a easier solution of (n*m) - 1
#include <bits/stdc++.h>
using namespace std;

int DP[301][301];

int solve(int n, int m){
    if(n == 1 && m == 1){
        return 0;
    }

    if(DP[n][m] != -1) return DP[n][m];
    int ans = 1e9;
    
    //Split by m or n
    for(int i = 1; i < m; i++){
        ans = min(ans, solve(n, i) + solve(n, m-i) + 1);
    }

    for(int i = 1; i < n; i++){
        ans = min(ans, solve(i, m) + solve(n-i, m) + 1);
    }

    DP[n][m] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(DP, -1, sizeof(DP));
    int n, m;
    cin >> n >> m;

    cout << solve(n, m);

}
