#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int coin_cnt, need_val;
    cin >> coin_cnt >> need_val;

    int DP[10001];
    memset(DP, -1, sizeof(DP));
    DP[0] = 0;

    vector<int> coins(coin_cnt);
    for(int i = 0; i < coin_cnt; i++){
        cin >> coins[i];
    }

    for(int i = 0; i < coin_cnt; i++){
        for(int j = 1; j <= need_val; j++){
            if(j - coins[i] >= 0){
                //Not made yet
                if(DP[j - coins[i]] == -1) continue;
                //If the current number has not been made yet, or the current value of DP[j] is bigger then the next upcoming value
                if(DP[j] == -1 || DP[j] > DP[j - coins[i]] + 1) DP[j] = DP[j - coins[i]] + 1;
            }
        }
    }
    
    cout << DP[need_val];

}
