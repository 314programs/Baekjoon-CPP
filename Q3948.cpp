#include <bits/stdc++.h>
using namespace std;

long long DP[22];
long long comb[22][22];

long long solve(int n){
    //Memoization
    if(DP[n] != -1) return DP[n];
    long long &ans = DP[n];
    ans = 0;

    for(int i = 1; i <= n; i += 2){
        //For all possible combinations comb[n-1][i-1]
        //ppl on the left: solve(i-1), right: solve(n-i)
        ans += comb[n-1][i-1] * solve(i-1) * solve(n-i);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int tc;
    cin >> tc;
    
    //Calculate combinations beforehand using pascal's triangle
    comb[0][0] = 1;
    for(int i = 1; i <= 20; i++){
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1; j <= i; j++){
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        }
    }

    memset(DP, -1, sizeof(DP));
    DP[0] = DP[1] = DP[2] = 1;

    while(tc--){
        int n;
        cin >> n;
        //Will not be multiplied by 2
        if(n == 1){
            cout << 1 << "\n";
        }
        else{
            //2 possibilities tall short tall or short tall short, so multiply by 2
            cout << 2LL*solve(n) << "\n";
        }
    }

}
