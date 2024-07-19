#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    int cnt = 1;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(n%i == 0){
            if(cnt == k){
                ans = i;
                break;
            }
            cnt++;
        }
    }
    cout << ans;

}
