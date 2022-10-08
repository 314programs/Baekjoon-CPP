#include <bits/stdc++.h>
using namespace std;

//Current number, how many times turned left (increase)
//Code is same as Q13392 but with backtracking
int DP[10000][10];
int backtrack[10000][10];
//Go to which idx, which turn?
int to[10000][21];

int n;
string s1, s2;

int solve(int idx, int turn){
    if(idx == n){
        return 0;
    }
    if(DP[idx][turn] != -1) return DP[idx][turn];
    
    
    int current = ((s1[idx] - '0') + turn)%10;

    int left_cost = ((s2[idx] - '0') - current + 10)%10;
    int l = solve(idx+1, (turn + left_cost)%10) + left_cost;

    int right_cost = (current - (s2[idx] - '0') + 10)%10;
    int r = solve(idx+1, turn) + right_cost;

    if(l < r){
        DP[idx][turn] = l;
        backtrack[idx][turn] = left_cost;
        //Added 10 to make maximum 20
        //0-9 is the right cost, 10-19 is the left cost
        to[idx][left_cost + 10] = (turn + left_cost)%10;
    }
    else{
        DP[idx][turn] = r;
        //Make right cost negative
        backtrack[idx][turn] = -right_cost;
        to[idx][-right_cost + 10] = turn;
    }
    return DP[idx][turn];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    cin >> s1 >> s2;
    memset(DP, -1, sizeof(DP));
    cout << solve(0, 0) << "\n";
    
    //Print backtracked items
    int temp = 0;
    for(int i = 0; i < n; i++){
        cout << i+1 << " " << backtrack[i][temp] << "\n";
        temp = to[i][backtrack[i][temp] + 10];
    }

}
