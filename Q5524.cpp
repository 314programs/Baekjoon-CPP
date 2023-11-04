#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    while(n--){
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout << s << "\n";
    }

}
