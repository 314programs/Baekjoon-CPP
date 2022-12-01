#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k, b;
    cin >> n >> k >> b;

    int a[n+1];
    int sum[n+1];
    sum[0] = 0;

    for(int i = 0; i <= n; i++){
        a[i] = 1;
    }
    
    for(int i = 0; i < b; i++){
        int num;
        cin >> num;
        a[num] = 0;
    }

    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1] + a[i];
    }

    int ans = 200000;
    for(int i = 0; i <= n-k; i++){
        ans = min(max(k-(sum[i+k]-sum[i]), 0), ans);
    }
    cout << ans;

}
