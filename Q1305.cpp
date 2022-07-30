#include <bits/stdc++.h>
using namespace std;

//KMP...
vector<int> pre_process(string p){
    int p_len = p.size();
    vector<int> pi(p_len);
    pi[0] = 0;
    int j = 0;

    for(int i = 1; i < p_len; i++){
        while(j > 0 && p[i] != p[j]) j = pi[j-1];
        if(p[i] == p[j]){
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

    int len;
    cin >> len;

    string p;
    cin >> p;

    auto temp = pre_process(p);
    cout << p.size() - temp[p.size()-1];
    
}
