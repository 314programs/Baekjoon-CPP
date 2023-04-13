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

int n, m, c;
bool check(vector<int> &a, int t){
    int num = 0;
    int team = 0;
    int ini = -1;
    for(int i = 0; i < n; i++){
        if(ini == -1){
            ini = a[i];
        }
        num++;

        if(a[i] - ini > t){
            team++;
            num = 1;
            ini = a[i];
        }
        else if(a[i] - ini <= t && num == c){
            team++;
            num = 0;
            ini = -1;
        }
    }
    if(num != 0) team++;

    if(team <= m) return true;
    else return false;

}

int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    setIO("");

    cin >> n >> m >> c;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int l = 0, r = 1e9;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(a, mid)){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << r+1;

}
