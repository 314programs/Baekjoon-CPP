#include <bits/stdc++.h>
using namespace std;

//Current number, how many times turned left (increase)
int DP[10000][10];
int n;
string s1, s2;

int solve(int index, int turn){
    if(index == n) return 0;
    if(DP[index][turn] != -1) return DP[index][turn];
    
    //Modulo by 10 since spinning more then that doesn't matter
    int current = ((s1[index] - '0') + turn)%10;
    
    //Increasing, effects later wheels
    int left_cost = ((s2[index] - '0') - current + 10)%10;
    //Add left cost to the turns due to cost
    int l = solve(index+1, (turn + left_cost)%10) + left_cost;
    
    //Decreasing, dosen't effect later wheels
    int right_cost = (current - (s2[index] - '0') + 10)%10;
    int r = solve(index+1, turn) + right_cost;

    DP[index][turn] = min(l ,r);
    return DP[index][turn];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    cin >> s1 >> s2;
    memset(DP, -1, sizeof(DP));
    cout << solve(0, 0);

}
