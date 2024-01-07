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

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> b(n);
    b = a;
    sort(b.begin(), b.end());

    map<int, pair<int, int>> m;
    for(int i = 0; i < n; i++){
        if(m.count(b[i]) == 0){
            m[b[i]] = make_pair(i, i);
        }
        else{
            m[b[i]].second = i;
        }
    }

    int mx = 0;
    for(int i = 0; i < n; i++){
        if(a[i] <= b[i]){
            mx = max(mx, min(abs(m[a[i]].first - i), i));
            m[a[i]].first++;
        }
    }
    mx++;
    cout << mx;
    
}
