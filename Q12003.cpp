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

int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    setIO("");

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int left[n];
    int l = 0, r = 0;
    for(; l < n; l++){
        while(r < n && a[r] <= a[l] + k) r++;
        left[l] = r-l;
    }

    int right[n+1];
    memset(right, 0, sizeof(right));
    for(int i = n-1; i >= 0; i--){
        right[i] = max(right[i+1], left[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, left[i] + right[left[i] + i]);
    }
    cout << ans;

}
