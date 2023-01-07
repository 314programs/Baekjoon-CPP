#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int ppl_cnt;
    cin >> ppl_cnt;
    
    //Dictionary
    map<string, bool> m;
    vector<string> names;

    while(ppl_cnt--){
        string ppl, status;
        cin >> ppl >> status;

        if(m.count(ppl) == 0){
            names.push_back(ppl);
        }

        if(status == "enter"){
            m[ppl] = true;
        }
        else{
            m[ppl] = false;
        }
    }

    sort(names.begin(), names.end());
    reverse(names.begin(), names.end());
    
    for(auto ch: names){
        if(m[ch] == true){
            cout << ch << "\n";
        }
    }

}
