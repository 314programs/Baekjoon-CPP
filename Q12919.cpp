#include <bits/stdc++.h>
using namespace std;
string S;

//Using functions for repetitive code
string reverse_(string T){
    reverse(T.begin(), T.end());
    return T;
}

string cut(string T){
    T.pop_back();
    return T;
}

bool can(string T){
    if(S == T) return true;
    if(T[0] == 'B' && can(cut(reverse_(T)))){
        return true;
    }
    if(T.back() == 'A' && can(cut(T))){
        return true;
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string T;
    cin >> S;
    cin >> T;

    bool can_make = can(T);
    if(can_make) cout << 1;
    else cout << 0;
}
