#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

struct milk_sell{
    int max_sell, price;
};

int calc_price(vector<milk_sell> &sell, int milk, bool change){
    int idx = sell.size()-1;
    int total = 0;

    while(milk && idx >= 0){
        if(sell[idx].max_sell > milk){
            total += sell[idx].price * milk;
            if(change) sell[idx].max_sell -= milk;
            break;
        }
        else if(sell[idx].max_sell <= milk){
            total += sell[idx].price * sell[idx].max_sell;
            milk -= sell[idx].max_sell;
            if(change) sell.pop_back();
        }
        idx--;
    }
    return total;

}


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> cows(n);
    int total = 0;
    for(int i = 0; i < n; i++){
        cin >> cows[i];
        total += cows[i];
    }
    sort(cows.begin(), cows.end(), greater<int>());



    vector<milk_sell> sell(m);
    for(int i = 0; i < m; i++){
        cin >> sell[i].max_sell >> sell[i].price;
    }
    sort(sell.begin(), sell.end(), [&](milk_sell &u, milk_sell &v){
        return u.price < v.price;
    });


    
    vector<int> rent(r);
    for(int i = 0; i < r; i++){
        cin >> rent[i];
    }
    sort(rent.begin(), rent.end(), greater<int>());
    
    vector<int> pref(r+1);
    for(int i = 1; i <= r; i++){
        pref[i] = pref[i-1] + rent[i-1];
    }

    int ans = pref[min(n, r)];
    int sold = 0;

    for(int i = 0; i < n; i++){
        int rent_m = pref[max(min(n-i-1, r), 0LL)];
        int calced = calc_price(sell, cows[i], true);
        sold += calced;
        ans = max(rent_m + sold, ans);
    }
    cout << ans;

}
