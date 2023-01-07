//Was confused with this at first, but figured out how to do it
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> t[n+1];

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max((int)t[i].size()+1, ans);
    }
    cout << ans;

}
