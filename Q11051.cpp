#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    //Using pascal's triangle
    long long DP[1003][1003];
    memset(DP, 0, sizeof(DP));

    long long n, k;
    cin >> n >> k;
    n++;
    k++;

    DP[1][1] = 1;
    for(int y = 2; y <= n; y++){
        for(int x = 1; x <= y; x++){
            DP[y][x] = (DP[y-1][x] + DP[y-1][x-1]) % 10007;
        }
    }

    cout << DP[n][k];

}
