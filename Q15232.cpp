#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int h, w;
    cin >> h >> w;

    string s = string(w, '*');
    for(int i = 0; i < h; i++){
        cout << s << "\n";
    }

}
