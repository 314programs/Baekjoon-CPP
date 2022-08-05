#include <bits/stdc++.h>
using namespace std;

//KMP
vector<int> pre_processing(string &s){
    int s_len = s.length();
    vector<int> pi(s_len);
    pi[0] = 0;
    int j = 0;

    for(int i = 1; i < s_len; i++){
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]){
            pi[i] = j + 1;
            j++;
        }
        else{
            pi[i] = 0;
        }
    }
    return pi;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
	
    string s;
    cin >> s;

    int s_len = s.length();
    vector<int> pi = pre_processing(s);
    vector<pair<int, int>> ans;
    vector<int> cnt(s_len+1, 0);
    
    //Count the fail values
    for(int i = 0; i < s_len; i++){
        cnt[pi[i]] += 1;
    }
    //All fail values bigger then the number can be divided into smaller fail values
    //Stack them up
    for(int i = s_len; i > 0; i--){
        cnt[pi[i-1]] += cnt[i];
    }
    
    //Finding all small fail values and storing them in a vector for answering
    for(int i = s_len; i != 0; i = pi[i-1]){
        ans.push_back(make_pair(i, cnt[i]+1));
    }
    reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for(auto ch: ans){
        cout << ch.first << " " << ch.second << "\n";
    }

    
}
