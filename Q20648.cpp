#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

int pref[2501][2501];
int pr_sum(int x1, int y1, int x2, int y2){
    return pref[x2+1][y2+1] - pref[x2+1][y1] - pref[x1][y2+1] + pref[x1][y1];
}

bool y_comp(pair<int,int> &u, pair<int,int> &v){
    return u.second < v.second;
}
 
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);

    map<int, int> m_x;
    map<int, int> m_y;
    vector<int> x_coord;
    vector<int> y_coord;

    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        x_coord.push_back(a[i].first);
        y_coord.push_back(a[i].second);
    }

    sort(x_coord.begin(), x_coord.end());
    sort(y_coord.begin(), y_coord.end());
    for(int i = 0; i < n; i++){
        m_x[x_coord[i]] = i;
        m_y[y_coord[i]] = i;
    }

    sort(a.begin(), a.end(), y_comp);
    memset(pref, 0, sizeof(pref));
    for(int i = 0; i < n; i++){
        a[i].first = m_x[a[i].first]+1;
        a[i].second = m_y[a[i].second]+1;
        pref[a[i].first][a[i].second] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            pref[i][j] = pref[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
        }
    }


    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int x1 = min(a[i].first, a[j].first)-1;
            int x2 = max(a[i].first, a[j].first)-1;
            ans += pr_sum(0,i,x1,j) * pr_sum(x2,i,n-1,j);
        }
    }
    cout << ans+1;


}
