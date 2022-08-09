#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int len;
    cin >> len;

    long long DP[101];
    memset(DP, -1, sizeof(DP));
    DP[0] = 0;

    for(int i = 1; i <= len; i++){
        DP[i] = DP[i-1]+1;
        //Paste how many times?
        for(int j = 1; j <= i - 3; j++){
            DP[i] = max(DP[i], DP[i-(j+2)] * (j+1));
        }
    }

    cout << DP[len];

}
