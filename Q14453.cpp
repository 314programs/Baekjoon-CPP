#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

//Small data can be bruteforced
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    //0: H, 1: P, 2:S
    int sum[3][n+1];

    sum[0][0] = 0;
    sum[1][0] = 0;
    sum[2][0] = 0;

    for(int i = 1; i <= n; i++){
        char c;
        cin >> c;

        for(int j = 0; j < 3; j++){
            sum[j][i] = sum[j][i-1];
        }
        if(c == 'H') sum[1][i]++;
        else if(c == 'P') sum[2][i]++;
        else sum[0][i]++;
    }

    int ans = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 1; k <= n; k++){
                ans = max(ans, (sum[i][k-1] - sum[i][0]) + (sum[j][n] - sum[j][k-1]));
            }
        }
    }
    cout << ans;

}
