#include <bits/stdc++.h>
using namespace std;

//Start, end, difference = end - start
int DP[2001][2001];
vector<int> a;

int solve(int i, int j){
    //Out of range
    if(i > j) return 0;
    //Equal number means sequence has size of 1, but this is actually not needed as all numbers are unique now
    if(i == j) return 1;

    //Memoization
    int &ans = DP[i][j];
    if(ans != 0){
        return ans;
    }

    //Get next value
    int diff = a[j] - a[i];
    int next = a[j] + diff;
    //If next value exists, move onto next value
    int p = lower_bound(a.begin(), a.end(), next) - a.begin();
    if(a[p] == next){
        return ans + solve(j, p) + 1;
    }
    else{
        //a[i] and a[j] is only part of sequence
        return ans = 2;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int ans = 1;
    int cnt = 1;
    //For same numbers, d = 0
    for(int i = 1; i < n; i++){
        if(a[i] == a[i-1]){
            cnt++;
            ans = max(cnt, ans);
        }
        else{
            cnt = 1;
        }
    }

    //Erase numbers that are not unique
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    memset(DP, 0, sizeof(DP));

    //All combinations of start and end
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            int current = solve(i, j);
            ans = max(ans, current);
        }
    }
    cout << ans;

}
