#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;

    int cnt = 0;
    while(n--){
        string s;
        cin >> s;

        int days = stoi(s.substr(2));
        if(days <= 90){
            cnt++;
        }
    }
    cout << cnt;

}
