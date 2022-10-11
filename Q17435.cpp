#include <bits/stdc++.h>
using namespace std;

int dp[200001][20];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> dp[i][0];
    }
    
    //2^19 is... 524288, larger then the upper bound for n...
    for(int j = 1; j < 20; j++){
        //Similar structure to LCA DP
        for(int i = 1; i <= n; i++){
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }

    int q;
    cin >> q;
    while(q--){
        int m, x;
        cin >> m >> x;
        for(int i = 0; i < 20; i++){
            //Find largest possible value by adding binary numbers together
            if(m & (1 << i)){
                x = dp[x][i];
            }
        }
        cout << x << "\n";
    }
    
    
}
