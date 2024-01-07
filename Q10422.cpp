#include <bits/stdc++.h>
using namespace std;

long long DP[5001];
long long mod = 1000000007;

long long solve(int len){
    if(len == 0){
        return 1;
    }
    //Memoization
    if(DP[len] != -1) return DP[len];

    DP[len] = 0;
    //Divide possible string into 2 parts, calculate and combine
    for(int i = 2; i <= len; i+=2){
        //All possibilities
        DP[len] += solve(i - 2) * solve(len - i);
        DP[len] %= mod;
    }
    return DP[len];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(DP, -1, sizeof(DP));
    int tc;
    cin >> tc;

    while(tc--){
        int num;
        cin >> num;
        if(num%2 == 0){
            cout << solve(num) << "\n";
        }
        //Can never match
        else{
            cout << 0 << "\n";
        }
    }

}
