#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

struct bound{
    int x_min, y_min, x_max, y_max;
};

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    fstream cin;
    cin.open("art.in");
    ofstream cout;
    cout.open("art.out");

    int n;
    cin >> n;

    if(n == 1) cout << 1;
    else{
        vector<vector<int>> a(n, vector<int>(n));
        map<int, bound> visible;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
                int c = a[i][j];

                if(!visible.count(c)){
                    visible[c] = {j, i, j, i};
                }
                visible[c].x_max = max(visible[c].x_max, j);
                visible[c].x_min = min(visible[c].x_min, j);
                visible[c].y_max = max(visible[c].y_max, i);
                visible[c].y_min = min(visible[c].y_min, i);
            }
        }
        visible.erase(0);

        int possible = n*n - visible.size();

        if(visible.size() > 1){
            vector<vector<int>> pref(n+1, vector<int>(n+1));
            set<int> valid_colors;

            for(auto &[c, b]: visible){
                valid_colors.insert(c);
                pref[b.y_min][b.x_min]++;
                pref[b.y_min][b.x_max + 1]--;
                pref[b.y_max + 1][b.x_min]--;
                pref[b.y_max + 1][b.x_max + 1]++;
            }

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i > 0) pref[i][j] += pref[i-1][j];
                    if(j > 0) pref[i][j] += pref[i][j-1];
                    if(i > 0 && j > 0) pref[i][j] -= pref[i-1][j-1];

                    if(pref[i][j] > 1){
                        valid_colors.erase(a[i][j]);
                    }
                }
            }
            possible += valid_colors.size();
        }

        cout << possible;
    }
    
}
