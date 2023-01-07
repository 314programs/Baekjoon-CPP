//Learning about Rabin-Karp algorithm
#include <bits/stdc++.h>
using namespace std;

int mod = 127;
int base = 256;

int h(string s){
    int ans = 0;
    for(auto ch: s){
        ans = ((ans * base) + ch) % mod;
    }
    return ans;
}

int match(string & s, string & p){
    int s_len = s.length();
    int p_len = p.length();

    if(p_len > s_len) return 0;

    int p_hash = h(p);
    int s_hash = h(s.substr(0, p_len));
    int first = 1;

    for(int i = 0; i < p_len - 1; i++){
        first = (first * base) % mod; 
    }

    for(int i = 0; i <= s_len - p_len; i++){
        if(p_hash == s_hash){
            if(p == s.substr(i, p_len)) return 1;
        }
        if(i + p_len < s_len){
            s_hash = s_hash - (first * s[i])%mod;
            s_hash = (s_hash + mod)%mod;
            s_hash = ((s_hash * base)%mod + s[i+p_len])%mod;
        }
    }
    return 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s, p;
    cin >> s >> p;
    cout << match(s, p);
}
