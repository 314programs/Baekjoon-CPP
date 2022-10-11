#include <bits/stdc++.h>
using namespace std;

bool DP[31][31][31][500];
int len, pair_cnt;
char ans[32];

//Keep adding characters and update the number of pairs that can be made...
bool solve(int idx, int a_cnt, int b_cnt, int pairs){
    //Reached ans
    if(idx == len){
        if(pairs == pair_cnt) return true;
        return false;
    }
    
    //Memoization...
    if(DP[idx][a_cnt][b_cnt][pairs]) return false;
    DP[idx][a_cnt][b_cnt][pairs] = true;

    ans[idx] = 'A';
    if(solve(idx+1, a_cnt+1, b_cnt, pairs)) return true;

    ans[idx] = 'B';
    if(solve(idx+1, a_cnt, b_cnt+1, pairs + a_cnt)) return true;

    ans[idx] = 'C';
    if(solve(idx+1, a_cnt, b_cnt, pairs + a_cnt + b_cnt)) return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(DP, false, sizeof(DP));
    cin >> len >> pair_cnt;
    bool can_print = solve(0, 0, 0, 0);
    
    //Print ans
    if(can_print){
        for(int i = 0; i < len; i++) cout << ans[i];
    }
    else{
        cout << -1;
    }
}
