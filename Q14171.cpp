#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    map<string, int> m;
    int ans = 0;

    for(int i = 0; i < n; i++){
        string region, state;
        cin >> region >> state;
        string s = region.substr(0, 2) + state;
        //Must come from different states
        if(region.substr(0, 2) != state){
            if(m.count(s) == 0) m[s] = 0;
            m[s] += 1;
        }
    }
    
    //Add up all possible pairs
    for(auto &ch: m){
        string s = ch.first.substr(2, 2) + ch.first.substr(0, 2);
        if(m.count(s) != 0){
            ans += m[s] * m[ch.first];
        }
    }
    
    //Counted doubles so divide by 2
    cout << ans/2;

}
