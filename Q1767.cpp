#include <bits/stdc++.h>
using namespace std;

long long DP[101][101][101];

long long solve(int n, int m, int k){
    if(k == 0) return 1;
    if(n <= 0 || m <= 0 || k < 0) return 0;

    if(DP[n][m][k] != -1) return DP[n][m][k];
    DP[n][m][k] = 0;
    
    //Rook is always placed on nth row
    //No rook
    DP[n][m][k] += solve(n-1, m, k) +
        //Put 1 rook, but does not get attacked
        solve(n-1, m-1, k-1) * m +
        //2 rooks
        solve(n-1, m-2, k-2) * m * (m-1)/2 +
        //Put one rook that gets attacked
        solve(n-2, m-1, k-2) * m * (n-1);

    DP[n][m][k] %= 1000001;
    return DP[n][m][k];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(DP, -1, sizeof(DP));
    int n, m, k;
    cin >> n >> m >> k;

    cout << solve(n, m, k);

}
