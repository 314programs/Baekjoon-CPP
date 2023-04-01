//prefix sum + implementation

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

int diamond(int x, int y, int k, int n, vector<vector<int>> &pref){
    int total = 0;

    for(int i = max(y-k, 1LL); i <= y; i++){
        int d = i-(y-k);
        int left_x = max(1LL, x-d);
        int right_x = min(n, x+d);
        total += pref[i][right_x] - pref[i-1][right_x] - pref[i][left_x-1] + pref[i-1][left_x-1];
    }

    for(int i = y+1; i <= min(y+k, n); i++){
        int d = y+k-i;
        int left_x = max(1LL, x-d);
        int right_x = min(n, x+d);
        total += pref[i][right_x] - pref[i-1][right_x] - pref[i][left_x-1] + pref[i-1][left_x-1];
        d--;
    }

    return total;

}

 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    int a[n][n];
    vector<vector<int>> pref(n+1, vector<int>(n+1, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            pref[i][j] = a[i-1][j-1] + pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1];
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int temp = diamond(j, i, k, n, pref);
            ans = max(temp, ans);
        }
    }
    cout << ans;
    
 
}
