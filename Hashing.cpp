#include <bits/stdc++.h>
using namespace std;

int mod = 127;
int base = 256;

int h(string p){
    int ans = 0;
    for(auto ch: p){
        ans = ((ans * base) + ch)%mod;
    }
    return ans;
}

int match(string p, string s){
    int p_len = p.length();
    int s_len = s.length();

    int hashed_p = h(p);
    int hashed_s = h(s.substr(0, p_len));
    int multi = 1;

    for(int i = 0; i < p_len-1; i++){
        multi = (base * multi) % mod;
    }

    if(p_len > s_len) return 0;

    for(int i = 0; i <= s_len - p_len; i++){
        if(hashed_s == hashed_p){
            if(p == s.substr(i, p_len)) return 1;
        }

        hashed_s = (hashed_s - (multi * s[i])) % mod;
        hashed_s = (hashed_s + mod) % mod;
        hashed_s = ((hashed_s * base)%mod + s[i + p_len])% mod;
    }
    return 0;
}
