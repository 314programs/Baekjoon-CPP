#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int ppl_cnt;
    cin >> ppl_cnt;

    vector<int> ppl(ppl_cnt);
    for(int i = 0; i < ppl_cnt; i++){
        cin >> ppl[i];
    }

    long long ans = 0;
    stack<pair<int, int>> s;

    for(int i = 0; i < ppl_cnt; i++){
        pair<int, int> ch = {ppl[i], 1};
        while(!s.empty()){
            //While the current person is the tallest
            if(ch.first >= s.top().first){
                ans += s.top().second;
                //People with same height can see same number of people + 1
                if(ch.first == s.top().first){
                    ch.second += s.top().second;
                }
                s.pop();
            }
            else{
                break;
            }
        }

        if(!s.empty()) ans++;
        s.push(ch);
    }
    cout << ans;
}
