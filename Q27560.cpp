#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    int n;
    cin >> n;

    vector<int> a(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int i = 0;
    vector<char> route;
    while(!(i == 0 && a[i] == 0)){
        while(a[i] > 0){
            route.push_back('R');
            a[i]--;
            i++;
        }
        while(i > 0 && (a[i-1] > 1 || a[i] == 0)){
            route.push_back('L');
            i--;
            a[i]--;
        }
    }

    for(auto ch: route){
        cout << ch;
    }
 
}
