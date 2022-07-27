#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    map<string, int> ppl_m;
    vector<string> names;

    while(n--){
        string ppl;
        cin >> ppl;

        if(ppl_m.count(ppl) == 0){
            names.push_back(ppl);
            ppl_m[ppl] = 1;
        }
    }

    int cnt = 0;
    while(m--){
        string ppl;
        cin >> ppl;

        if(ppl_m.count(ppl) == 0){
            names.push_back(ppl);
            ppl_m[ppl] = 1;
        }
        else{
            ppl_m[ppl]++;
            cnt++;
        }
    }

    cout << cnt << "\n";
    sort(names.begin(), names.end());
    
    for(auto ch: names){
        if(ppl_m[ch] == 2){
            cout << ch << "\n";
        }
    }

}
