#include <bits/stdc++.h>
using namespace std;

vector<int> bale;
int n;
int visited[1001];

//Explosion simulation
int solve(int start, int idx){
    int ans = 1;
    int idx_add = 1;

    idx_add = 1;
    vector<int> temp1;
    //First mark the explosions then explode them
    //Initially made mistake of exploding bales that was already exploded
    while(idx - idx_add >= 0 && abs(bale[idx-idx_add] - bale[idx]) <= visited[idx] && visited[idx-idx_add] == 0){
        visited[idx-idx_add] = visited[idx]+1;
        temp1.push_back(idx-idx_add);
        idx_add++;
    }
    for(auto ch: temp1){
        ans += solve(bale[ch], ch);
    }

    idx_add = 1;
    vector<int> temp2;
    while(idx + idx_add < n && abs(bale[idx+idx_add] - bale[idx]) <= visited[idx] && visited[idx+idx_add] == 0){
        visited[idx+idx_add] = visited[idx]+1;
        temp2.push_back(idx+idx_add);
        idx_add++;
    }
    for(auto ch: temp2){
        ans += solve(bale[ch], ch);
    }

    return ans;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;

    bale.resize(n);
    for(int i = 0; i < n; i++){
        cin >> bale[i];
    }

    sort(bale.begin(), bale.end());
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        ans = max(solve(bale[i], i), ans);
    }
    cout << ans;

}
