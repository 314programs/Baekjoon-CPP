#include <bits/stdc++.h>
using namespace std;

int a[50];
//till which idx of block used, difference
int DP[50][250001];
int const inf = 2000000000;
int n;

//k = idx of block, diff = height of tall building - height of short building
int solve(int k, int diff){
    if(diff > 250000){
        return -inf;
    }
    if(k == n){
        //Only same height allowed
        if(diff == 0){
            return 0;
        }
        else{
            return -inf;
        }
    }

    int &ans = DP[k][diff];
    if(ans != -1){
        return ans;
    }

    //Don't place block
    ans = solve(k+1, diff);
    //Place block on tall building
    ans = max(ans, solve(k+1, diff + a[k]));

    //Place building on short building
    if(a[k] < diff){
        ans = max(ans, a[k] + solve(k+1, diff-a[k]));
    }
    else{
        ans = max(ans, diff + solve(k+1, a[k]-diff));
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    memset(DP, -1, sizeof(DP));

    int ans = solve(0, 0);
    if(ans == 0){
        cout << -1;
    }
    else{
        cout << ans;
    }
}
