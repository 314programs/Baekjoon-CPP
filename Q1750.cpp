#include <bits/stdc++.h>
using namespace std;

int a[50];
//idx of array used, current gcd
long long DP[50][100001];
int n;
const long long mod = 10000003;

//GCD function
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}

long long solve(int idx, int factor){
    if(idx >= n){
        if(factor == 1){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(DP[idx][factor] != -1){
        return DP[idx][factor];
    }
    DP[idx][factor] = 0;

    //Not add
    DP[idx][factor] += solve(idx+1, factor);
    DP[idx][factor] %= mod;

    //Add
    if(factor == -1){
        factor = a[idx];
        DP[idx][factor] += solve(idx+1, factor);
    }
    else{
        int temp = gcd(a[idx], factor);
        DP[idx][factor] += solve(idx+1, temp);
    }
    DP[idx][factor] %= mod;
    return DP[idx][factor];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    memset(DP, -1, sizeof(DP));
    cout << solve(0, 0);

}
