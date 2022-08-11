#include <bits/stdc++.h>
using namespace std;

int brand[1000];
int DP[1000][1000];

int solve(int i, int j){
    if(i >= j){
        return 0;
    }
    
    //Memoization
    int &ans = DP[i][j];
    if(ans != -1) return ans;

    for(int x = i+1; x <= j; x++){
        if(brand[i] == brand[x]){
            //Split if match has been found
            ans = max(ans, solve(i+1, x-1) + solve(x+1, j) + 1);
        }
    }
    
    //Move foward, ignore the current person
    ans = max(ans, solve(i+1, j));
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(DP, -1, sizeof(DP));
    int ppl_cnt;
    cin >> ppl_cnt;

    for(int i = 0; i < ppl_cnt; i++){
        cin >> brand[i];
    }

    cout << solve(0, ppl_cnt-1);

}
