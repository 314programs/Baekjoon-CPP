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

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int min_move = 1e12;
    if(a[n-2] - a[0] == n-2 && a[n-1] - a[n-2] > 2){
        min_move = 2;
    }
    else if(a[n-1] - a[1] == n-2 && a[1] - a[0] > 2){
        min_move = 2;
    }
    else{
        int far_cow = 0;
        for(int i = 0; i < n; ++i){
            while(far_cow + 1 < n && a[far_cow + 1] - a[i] < n){
                far_cow++;
            }
            min_move = min(min_move, n - (far_cow - i + 1));
        }
    }

    int gap_num = 0;
    for(int i = 1; i < n; i++){
        gap_num += a[i] - a[i-1] - 1;
    }
    int max_move = max(gap_num - (a[1] - a[0] - 1), gap_num - (a[n-1] - a[n-2] - 1));
    cout << min_move << "\n" << max_move;

}
