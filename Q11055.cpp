//I did not do this???!?!?!??!

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    int DP[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        DP[i] = a[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[i] > a[j]){
                DP[i] = max(DP[i], DP[j] + a[i]);
            }
        }
    }

    int ans = 0;
    for(auto ch: DP){
        ans = max(ans, ch);
    }
    cout << ans;

}
