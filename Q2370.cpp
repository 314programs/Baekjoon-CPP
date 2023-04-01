#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    set<int> s;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        s.insert(a[i].first);
        s.insert(a[i].second);
    }

    int cnt = 0;
    map<int, int> m;
    for(auto ch: s){
        m[ch] = cnt++; 
    }

    vector<pair<int, int>> b(n);
    for(int i = 0; i < n; i++){
        b[i].first = m[a[i].first];
        b[i].second = m[a[i].second];
    }

    vector<vector<int>> pos(s.size()+2, vector<int>());
    for(int i = 0; i < n; i++){
        pos[b[i].first].push_back(i+1);
        pos[b[i].second+1].push_back(-(i+1));
    }

    set<int> ans;
    set<int> check;
    for(int i = 0; i <= s.size()+1; i++){
        for(auto ch: pos[i]){
            if(ch > 0){
                check.insert(ch);
            }
            else if(ch < 0){
                check.erase(abs(ch));
            }
        }
        if(!check.empty()) ans.insert(*check.rbegin());
    }

    cout << ans.size();


}
