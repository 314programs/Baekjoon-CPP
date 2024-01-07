#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int tower_cnt;
    cin >> tower_cnt;

    vector<int> tower(tower_cnt);
    for(int i = 0; i < tower_cnt; i++){
        cin >> tower[i];
    }

    vector<int> ans(tower_cnt, 0);
    stack<pair<int, int>> s;
    //Push element into stack
    for(int i = 0; i < tower_cnt; i++){
        int ch = tower[i];
        //While previous element is smaller then current element
        //Repeat until bigger or equal one is found
        while(!s.empty() && ch > s.top().first){
            s.pop();
        }
        
        //If previous element is bigger then current element, it connects
        //Put index of connection as answer
        if(!s.empty() && ch <= s.top().first){
            ans[i] = s.top().second;
        }
        s.push({ch, i+1});
    }
    
    bool print = false;
    for(auto ch: ans){
        if(ch > 0){
            print = true;
            break;
        }
    }
    if(print == false){
        cout << 0;
        return 0;
    }
    else{
        for(auto ch: ans){
            cout << ch << " ";
        }
    }
   
}
