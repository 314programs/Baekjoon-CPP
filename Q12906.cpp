//Array string was hard!
//The algorithm is easy, but way of storing is hard
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    array<string, 3> s;
    for(int i = 0; i < 3; i++){
        int cnt;
        cin >> cnt;
        if(cnt > 0){
            cin >> s[i];
        }
        else{
            s[i] = "";
        }
    }

    vector<int> tower_count = {0,0,0};
    for(int i = 0; i < 3; i++){
        for(auto ch: s[i]){
            tower_count[ch-'A']++;
        }
    }

    map<array<string, 3>, int> d;
    queue<array<string, 3>> q;
    q.push(s);
    d[s] = 0;

    while(!q.empty()){
        array<string, 3> temp = q.front();
        q.pop();

        for(int from = 0; from < 3; from++){
            for(int to = 0; to < 3; to++){
                if(from == to) continue;
                if(temp[from].length() == 0) continue;

                array<string, 3> next(temp);
                next[to].push_back(next[from].back());
                next[from].pop_back();

                if(d.count(next) == 0){
                    d[next] = d[temp] + 1;
                    q.push(next);
                }
            }
        }
    }

    array<string, 3> ans;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < tower_count[i]; j++){
            ans[i] += i + 'A';
        }
    }

    cout << d[ans];

}
