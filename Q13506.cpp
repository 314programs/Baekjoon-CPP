#include <bits/stdc++.h>
using namespace std;

//Kmp
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

int match(string & s, string & p){
    vector<int> pi = pre_processing(p);
    int s_len = s.length(), p_len = p.length();
    int j = 0;
    int cnt = 0;
    int special = 0;

    for(int i = 0; i < s_len; i++){
        while(j > 0 && s[i] != p[j]) j = pi[j-1];
        if(s[i] == p[j]){
            if(j == p_len - 1){
                //Checks suffix and prefix
                if(i == p_len - 1) special++;
                else if(i == s_len - 1) special++;
                //Others in the middle
                else cnt++;
                j = pi[j];
            }
            else{
                j++;
            }
        }
    }

    if(special == 2) return cnt;
    else return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
	
    string s;
    cin >> s;

    int s_len = s.length();
    int ans;
    vector<int> s_pi = pre_processing(s);
    bool found = false;
    
    //Start checking from longest suffix to get maximum
    for(int i = s_len-1; i > 0; i--){
        //Stopping because suffix != prefix anymore
        if(s_pi[i] == 0) break;

        ans = s_pi[i];
        //Sub string to search for during KMP
        string p = s.substr(0, s_pi[i]);
        int temp = match(s, p);
        
        //If string between suffix and prefix exists, maximum has been found
        if(temp >= 1){
            found = true;
            break;
        }
    }
    
    //Print
    if(found) cout << s.substr(0, ans);
    else cout << -1;
    
}
