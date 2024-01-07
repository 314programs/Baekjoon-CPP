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

int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    setIO("");

    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [&](auto &u, auto &v){
        return u.second < v.second;
    });

    int left = 0, right = n-1;
    int ans = 0;
    while(left <= right){
        ans = max(a[left].second + a[right].second, ans);
        if(a[left].first < a[right].first){
            a[right].first -= a[left].first;
            a[left].first = 0;
            left++;
        }
        else if(a[left].first > a[right].first){
            a[left].first -= a[right].first;
            a[right].first = 0;
            right--;
        }
        else{
            a[left].first = 0;
            a[right].first = 0;
            left++;
            right--;
        }
    }

    cout << ans;

}
