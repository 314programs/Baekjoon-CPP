#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int coin_cnt, need_val;
    cin >> coin_cnt >> need_val;

    int DP[10001];
    memset(DP, 0, sizeof(DP));
    DP[0] = 1;

    vector<int> coins(coin_cnt);
    for(int i = 0; i < coin_cnt; i++){
        cin >> coins[i];
    }
    
    //For every type of coin
    for(int i = 0; i < coin_cnt; i++){
        //For every number
        //If number j can be made using current number
        for(int j = 1; j <= need_val; j++){
            if(j - coins[i] >= 0) DP[j] += DP[j - coins[i]];
        }
    }
    cout << DP[need_val];

}
