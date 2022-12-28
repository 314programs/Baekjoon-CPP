//When can I fully understand logic from looking at a question...

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> radius(n);
    int minimum = 2e9;

    for(int i = 0; i < n; i++){
        cin >> radius[i];
        minimum = min(minimum, radius[i]);
        radius[i] = minimum;
    }

    vector<int> pizza(m);
    for(int i = 0; i < m; i++){
        cin >> pizza[i];
    }

    int cur = 0;
    int ans = 0;

    for(int i = n-1; i >= 0; i--){
        if(cur == m) break;
        if(radius[i] >= pizza[cur]){
            ans = i;
            cur++;
        }
    }

    if(cur < m) ans = -1;
    cout << ans+1;


}
