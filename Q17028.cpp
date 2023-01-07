//It works... somehow?
//Good thing physics test delayed
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 0; i < n-1; i++){
        //Find cow out of order at farthest place since each cow has to be moved
        if(a[i] > a[i+1]){
            ans = i+1;
        }
    }
    cout << ans;
 
}
