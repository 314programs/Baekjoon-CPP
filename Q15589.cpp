#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

struct cow{
    int time, idx;
    bool start;
};

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n;
    cin >> n;

    vector<cow> a;
    set<int> s;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        a.push_back({l, i, true});
        a.push_back({r, i, false});
    }

    sort(a.begin(), a.end(), [&](cow &u, cow &v){
        return u.time < v.time;
    });

    vector<int> alone(n);
    set<int> active;
    int prev_time = 0;
    int total_time = 0;

    for(auto ch: a){
        int cur_time = ch.time;
        if(active.size() > 0){
            total_time += cur_time - prev_time;
        }
        if(active.size() == 1){
            alone[*active.begin()] += cur_time - prev_time;
        }

        if(ch.start){
            active.insert(ch.idx);
        }
        else{
            active.erase(ch.idx);
        }
        prev_time = cur_time;
    }

    int min_time = *min_element(alone.begin(), alone.end());
    cout << total_time - min_time;

}
