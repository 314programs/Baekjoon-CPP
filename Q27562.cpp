#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long

struct stall{
    int start, end, reduce, cost;
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    int n, m;
    cin >> n >> m;

    vector<int> cows(101, 0);
    int l = 101, r = 0;
    for(int i = 0; i < n; i++){
        int l_, r_, c;
        cin >> l_ >> r_ >> c;
        for(int j = l_; j <= r_; j++){
            cows[j] = c;
        }
        l = min(l, l_);
        r = max(r, r_);
    }

    vector<stall> s(m);
    for(int i = 0; i < m; i++){
        cin >> s[i].start >> s[i].end >> s[i].reduce >> s[i].cost;
    }

    int ans = 1e9;
    for(int i = 1; i < (1 << m); i++){
        vector<int> temp(101, 0);
        int total_cost = 0;

        for(int j = 0; j < m; j++){
            if(i & (1 << j)){
                for(int k = s[j].start; k <= s[j].end; k++){
                    temp[k] += s[j].reduce;
                }
                total_cost += s[j].cost;
            }
        }

        bool can = true;
        for(int j = l; j <= r; j++){
            if(temp[j] < cows[j]){
                can = false;
                break;
            }
        }

        if(can){
            ans = min(ans, total_cost);
        }

    }
    cout << ans;

}
