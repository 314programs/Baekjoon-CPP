#include <bits/stdc++.h>
using namespace std;

bool DP[51][51][51][3][3];
int cnt[3] = {0, 0, 0};
char ans[51];
int s_len;

//p1 and p2 record what letter came a day before and 2 days before
bool solve(int a_cnt, int b_cnt, int c_cnt, int p1, int p2, int index){
    if(a_cnt == cnt[0] && b_cnt == cnt[1] && c_cnt == cnt[2]){
        return true;
    }
    if(index == s_len){
        return false;
    }

    if(DP[a_cnt][b_cnt][c_cnt][p1][p2]) return false;
    DP[a_cnt][b_cnt][c_cnt][p1][p2] = true;
    
    //Try every possible destination, make sure to use memoization to not take up too much time
    ans[index] = 'A';
    if(solve(a_cnt+1, b_cnt, c_cnt, 0, p1, index+1)) return true;

    if(p1 != 1){
        ans[index] = 'B';
        if(solve(a_cnt, b_cnt+1, c_cnt, 1, p1, index+1)) return true;
    }

    if(p1 != 2 && p2 != 2){
        ans[index] = 'C';
        if(solve(a_cnt, b_cnt, c_cnt+1, 2, p1, index+1)) return true;
    }
    return false;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;
    
    //Count letters
    for(auto ch: s){
        cnt[ch - 'A']++;
    }

    s_len = s.length();
    bool can = solve(0, 0, 0, -1, -1, 0);

    if(can) cout << ans;
    else cout << "-1";
}
