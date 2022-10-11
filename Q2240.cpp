#include <bits/stdc++.h>
using namespace std;

int fall[1001];
//seconds passed, tree, movement left
int DP[1001][3][31];
int sec, movement_cnt;

int solve(int s, int move, int tree){
    if(s == sec+1) return 0;
    if(move < 0) return 0;
    if(DP[s][tree][move] != -1) return DP[s][tree][move];

    if(tree == 1){
        //If fruit has been caught this second
        int t1 = 0;
        if(fall[s] == 1) t1 = 1;
        //Switch or stay?
        DP[s][tree][move] = max(solve(s+1, move, tree), solve(s+1, move-1, 2)) + t1;
    }

    if(tree == 2){
        int t2 = 0;
        if(fall[s] == 2) t2 = 1;
        DP[s][tree][move] = max(solve(s+1, move, tree), solve(s+1, move-1, 1)) + t2;
    }

    return DP[s][tree][move];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> sec >> movement_cnt;
    memset(DP, -1, sizeof(DP));

    for(int i = 1; i <= sec; i++){
        cin >> fall[i];
    }

    cout << solve(0, movement_cnt, 1) << "\n";

}
