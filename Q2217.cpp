//Did not read about the fact that I can remove some ropes...

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;
    int ans = 0;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());
    for(int i = 0; i < n; i++){
        ans = max(int(a.back()*a.size()), ans);
        a.pop_back();
    }
    cout << ans;

}
