//I needed to remove a space to get it correct...

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

vector<int> difference[300];
vector<int> ans;

bool ok(int n, int i){
    int max_ = -2e9;
    int min_ = 2e9;
    for(int j = i; j < n; j++){
        max_ = max(max_, ans[j]);
        min_ = min(min_, ans[j]);
        if(max_ - min_ != difference[i][j-i]){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;
    ans.resize(n, 0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i; j++){
            int num;
            cin >> num;
            difference[i].push_back(num);
        }
    }

    for(int i = n-2; i >= 0; i--){
        ans[i] = ans[i+1] + difference[i][1];
        if(!ok(n, i)){
            ans[i] = ans[i+1] - difference[i][1];
        }
    }

    for(int i = 0; i < n-1; i++){
        cout << ans[i] << " ";
    }
    cout << ans[n-1];

}
