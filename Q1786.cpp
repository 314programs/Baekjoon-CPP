//Learning about KMP... will update the code when I understand it more
#include <bits/stdc++.h>
using namespace std;

vector<int> pre_processing(string p){
    int m = p.size();
    vector<int> pi(m);
    pi[0] = 0;
    int j = 0;
    
    for(int i = 1; i < m; i++){
        while(j > 0 && p[i] != p[j]){
            j = pi[j-1];
        }

        if(p[i] == p[j]){
            pi[i] = j+1;
            j += 1;
        }
        else{
            pi[i] = 0;
        }
    }
    return pi;
}

vector<int> kmp(string s, string p){
    auto pi = pre_processing(p);
    vector<int> ans;
    int n = s.size(), m = p.size(), i = 0, j = 0;

    for(int i = 0; i < n; i++){
        while(j > 0 && s[i] != p[j]){
            j = pi[j-1];
        }

        if(s[i] == p[j]){
            if(j == m-1){
                ans.push_back(i-m+1);
                j = pi[j];
            }
            else{
                j += 1;
            }
        }
    }
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s, p;
    getline(cin, s);
    getline(cin, p);
    
    vector<int> ans = kmp(s, p);
    cout << ans.size() << "\n";
    for(auto ch: ans){
        cout << ch+1 << " ";
    }
    
}
