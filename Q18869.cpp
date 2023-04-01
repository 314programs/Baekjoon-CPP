//Recap about coordinate compression
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        map<int, int> mp;
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            mp[a[i][j]] = j;
        }
        sort(a[i].begin(), a[i].end());
        for(int j = 0; j < m; j++){
            b[i][j] = mp[a[i][j]];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(b[i] == b[j]) ans++;
        }
    }
    cout << ans;
 
}
