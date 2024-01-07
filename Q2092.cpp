#include <bits/stdc++.h>
using namespace std;

long long a[4001];
const long long MOD = 1000000;
//Number limit, length
long long DP[201][4001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int limit, list_len, start, end;
    cin >> limit >> list_len >> start >> end;

    memset(a, 0, sizeof(a));
    for(int i = 0; i < list_len; i++){
        int num;
        cin >> num;
        a[num]++;
    }

    DP[0][0] = 1;
    //Number limit
    for(int i = 1; i <= limit; i++){
        //Only one way to make set of 0 length using i as limit
        DP[i][0] = 1;

        //Length
        for(int j = 1; j <= list_len; j++){
            //How many number i can we use
            for(int k = 0; k <= a[i]; k++){
                //Adding k amount of number i to make a new set
                //Since we want to add, find the DP of previous number limit with j-k numbers inside
                if(j - k >= 0){
                    DP[i][j] += DP[i-1][j-k];
                    DP[i][j] %= MOD;
                }
            }
        }
    }

    long long ans = 0;
    //Add from start to end
    for(int i = start; i <= end; i++){
        ans += DP[limit][i];
        ans %= MOD;
    }
    cout << ans;

}
