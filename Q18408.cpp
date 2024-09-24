#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    map<int, int> m;
    int a;
    for(int i = 0; i < 3; i++){
        cin >> a;
        m[a]++;
    }
    
    if(m[1] > m[2]) cout << 1;
    else cout << 2;

}
