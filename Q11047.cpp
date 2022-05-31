#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    long long coin_count, total;
    cin >> coin_count >> total;
    int ans = 0;

    vector<long long> coins(10);
    for(int i = 0; i < coin_count; i++){
        cin >> coins[i];
    }

    for(int i = coin_count-1; i >= 0; i--){
        ans += total/coins[i];
        total %= coins[i];
    }
    cout << ans;
}
