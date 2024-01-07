#include <bits/stdc++.h>
using namespace std;

//Length, starting num
long long DP[11][100001];

//Sum of all DP[i]...
long long sum[11];
vector<int> dividers[100001];
long long mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= k; i++){
        for(int j = i + i; j <= k; j += i){
            dividers[j].push_back(i);
        }
    }

    memset(DP, 0, sizeof(DP));
    for(int i = 1; i <= k; i++){
        DP[1][i] = 1;
    }
    sum[1] = k;
    
    //There are 2 possibilities for B
    //B is bigger or equal or is not a factor
    //Since number of factors are smaller then non-factors, subtract the number of factors from the total
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= k; j++){
            DP[i][j] = sum[i-1];
            //Subtracting factors
            for(int div: dividers[j]){
                DP[i][j] -= DP[i-1][div];
                //Making sure answer is positive
                DP[i][j] %= mod;
                DP[i][j] += mod;
                DP[i][j] %= mod;
            }
            sum[i] += DP[i][j];
            sum[i] %= mod;
        }
    }
    cout << sum[n];

}
