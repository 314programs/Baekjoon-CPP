#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

void setIO(string s = ""){
    if(s == "") return;
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}

const int MOD = 1e9+7;
const int mx_N = 1e5;
const int mx_c = 1e4;

struct fence{
    int x, y;
    int height_sum, base_sum;
};

fence fc[mx_N];
vector<pair<int, int>> x_coords[2*mx_c + 1];
vector<pair<int, int>> y_coords[2*mx_c + 1];

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    setIO("triangles");

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> fc[i].x >> fc[i].y;
        x_coords[fc[i].x + mx_c].push_back({fc[i].y, i});
        y_coords[fc[i].y + mx_c].push_back({fc[i].x, i});
    }

    for(int i = 0; i <= 2*mx_c; i++){
        if(x_coords[i].size() > 0){
            int cur = 0;
            sort(x_coords[i].begin(), x_coords[i].end());

            for(int j = 1; j < x_coords[i].size(); j++){
                cur += x_coords[i][j].first - x_coords[i][0].first;
            }
            fc[x_coords[i][0].second].height_sum = cur;

            for(int j = 1; j < x_coords[i].size(); j++){
                cur += (2*j - x_coords[i].size()) * (x_coords[i][j].first - x_coords[i][j-1].first);
                fc[x_coords[i][j].second].height_sum = cur;
            }
        }
    }

    for(int i = 0; i <= 2*mx_c; i++){
        if(y_coords[i].size() > 0){
            int cur = 0;
            sort(y_coords[i].begin(), y_coords[i].end());

            for(int j = 1; j < y_coords[i].size(); j++){
                cur += y_coords[i][j].first - y_coords[i][0].first;
            }
            fc[y_coords[i][0].second].base_sum = cur;

            for(int j = 1; j < y_coords[i].size(); j++){
                cur += (2*j - y_coords[i].size()) * (y_coords[i][j].first - y_coords[i][j-1].first);
                fc[y_coords[i][j].second].base_sum = cur;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += fc[i].base_sum * fc[i].height_sum;
        ans %= MOD;
    }
    cout << ans;
    
}
