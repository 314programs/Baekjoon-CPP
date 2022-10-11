#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string S, T;
    getline(cin, S);
    getline(cin, T);

    while(S.length() != T.length()){
        if(T.back() == 'A'){
            T.pop_back();
        }
        else if(T.back() == 'B'){
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }

    if(S == T) cout << 1;
    else cout << 0;
    
}
