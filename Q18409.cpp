#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    int n;

    cin >> n;
    cin >> s;

    int cnt = 0;
    for(auto ch: s){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            cnt++;
        }
    }
    cout << cnt;


}
