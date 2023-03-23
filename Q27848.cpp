#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int inf = 1e9+7;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> route[n+1];

    for(int i = 0; i < m; i++){
        int c, r, d, s;
        cin >> c >> r >> d >> s;
        route[c].push_back({r, d, s});
    }

    vector<int> layover(n+1);
    for(int i = 1; i <= n; i++){
        cin >> layover[i];
    }
    layover[1] = 0;
    
    for(int c = 1; c <= n; c++){
        for(auto &ch: route[c]){
            ch[0] -= layover[c];
        }
        sort(route[c].begin(), route[c].end());
        reverse(route[c].begin(), route[c].end());
    }

    vector<int> time(n+1, inf);
    time[1] = 0;
    vector<int> idx(n+1, 0);

    vector<vector<int>> q;
    int qid = 0;

    for(auto ch: route[1]){
        q.push_back(ch);
    }

    while(qid < q.size()){
        int r = q[qid][0];
        int d = q[qid][1];
        int s = q[qid][2];
        time[d] = min(time[d], s);

        while(idx[d] < route[d].size() && route[d][idx[d]][0] >= s){
            q.push_back(route[d][idx[d]]);
            idx[d]++;
        }
        qid++;
    }

    for(int i = 1; i <= n; i++){
        if(time[i] < inf){
            cout << time[i] << "\n";
        }
        else{
            cout << "-1\n";
        }
    }



}
