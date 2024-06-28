#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

void setIO(string s = ""){
    if(s == "") return;
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}

string format[4][6];

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> LIS;
    for(auto ch: a){
        auto it = lower_bound(LIS.begin(), LIS.end(), ch);
        if(it == LIS.end()){
            LIS.push_back(ch);
        }
        else{
            *it = ch;
        }
    }

    cout << LIS.size();

}
