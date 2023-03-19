#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int tc;
    cin >> tc;

    while(tc--){
        string before, after;
        cin >> before >> after;

        map<char, char> becomes;
        bool possible = true;
        
        for(int i = 0; i < before.size(); i++){
            if(becomes.count(before[i]) == 1 && becomes[before[i]] != after[i]){
                possible = false;
            }
            becomes[before[i]] = after[i];
        }

        set<char> s;
        for(auto ch: after){
            s.insert(ch);
        }
        if(s.size() == 52 && before != after){
            possible = false;
        }

        if(possible){
            int ans = 0;
            map<char, int> indegree;

            for(auto r: alphabet){
                if(becomes.count(r) == 1 && becomes[r] != r){
                    if(indegree[becomes[r]] == 0) indegree[becomes[r]] = 1;
                    else indegree[becomes[r]] = indegree[becomes[r]] + 1;
                    ans++;
                }
            }

            map<char, char> seen;
            for(auto r: alphabet){
                if(seen.count(r) == 0){
                    auto a = r;
                    while(seen.count(a) == 0){
                        seen[a] = r;
                        if(becomes.count(a) == 0) a = a;
                        else a = becomes[a];
                    }

                    if(becomes.count(a) == 1 && a != becomes[a] && seen[a] == r){
                        auto s_ = a;
                        bool cycle = true;
                        while(true){
                            seen[a] = '0';
                            if(indegree[a] > 1){
                                cycle = false;
                            }
                            a = becomes[a];
                            if(a == s_){
                                break;
                            }
                        }
                        if(cycle) ans++;
                    }

                }
            }
            cout << ans << "\n";

        }
        else{
            cout << -1 << "\n";
        }


    }

}
