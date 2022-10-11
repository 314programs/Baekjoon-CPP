#include <bits/stdc++.h>
using namespace std;

int DP[61][61][61];

int solve(int i, int j, int k){
    if(i < 0) return solve(0, j, k);
    if(j < 0) return solve(i, 0, k);
    if(k < 0) return solve(i, j, 0);

    if(i == 0 && j == 0 && k == 0) return 0;
    
    //DP[i][j][k] will be updated for memoization
    int &ans = DP[i][j][k];
    if(ans != -1) return ans;

    ans = 1000000;
    //Try all possible combinations
    vector<int> p = {1,3,9};
    do{
        int temp = solve(i - p[0], j - p[1], k - p[2]);
        ans = min(temp, ans);
    }
    while(next_permutation(p.begin(), p.end()));

    ans++;
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(DP, -1, sizeof(DP));
    int cv_cnt;
    cin >> cv_cnt;
    
    int cv[3] = {0,0,0};
    for(int i = 0; i < cv_cnt; i++){
        cin >> cv[i];
    }

    cout << solve(cv[0], cv[1], cv[2]);

}
