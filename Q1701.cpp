#include <bits/stdc++.h>
using namespace std;

//Use the fail vector to find the longest equal prefix and suffix
vector<int> pre_process(string p){ 
    int p_len = p.size();
    vector<int> pi(p_len);
    pi[0] = 0;
    int j = 0;

    for(int i = 1; i < p_len; i++){
        while(j > 0 && p[i] != p[j]) j = pi[j-1];
        if(p[j] == p[i]){
            pi[i] = j+1;
            j++;
        }
        else{
            pi[i] = 0;
        }
    }
    return pi;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string p;
    cin >> p;
    int p_len = p.size();
    int ans = 0;
    //Repeat for each length, removing the starting letters each loop
    for(int i = 0; i < p_len; i++){
        auto temp = pre_process(p.substr(i, p_len-i));
        for(auto ch: temp){
            ans = max(ans, ch);
        }
    }

    cout << ans;
    
}
