#include <bits/stdc++.h>
using namespace std;

//number of buildings 0-n, left, right
long long DP[101][101][101];
const long long mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, l, r;
    cin >> n >> l >>r;

    memset(DP, 0, sizeof(DP));
    DP[1][1][1] = 1;
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= l; j++){
            for(int k = 1; k <= r; k++){
                DP[i+1][j+1][k] = (DP[i+1][j+1][k] + DP[i][j][k])%mod;
                DP[i+1][j][k+1] = (DP[i+1][j][k+1] + DP[i][j][k])%mod;
                //Previously mistaken for this part as I wrote down n-1 instead
                //Remember that current n will be i...
                DP[i+1][j][k] = (DP[i+1][j][k] + DP[i][j][k] * (i-1))%mod;
            }
        }
    }

    cout << DP[n][l][r];



}
