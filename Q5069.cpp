#include <bits/stdc++.h>
using namespace std;

int DP[29][29][15];
//Method for navigating through hexagonal space...
int dx[6] = {0, 1, 1, 0, -1, -1};
int dy[6] = {1, 0, -1, -1, 0, 1};

int solve(int x, int y, int move){
    //Back to start
    if(x == 14 && y == 14 && move == 0) return 1;
    //Not possible
    if(move < 0) return 0;
    //Memoization
    if(DP[x][y][move] != -1) return DP[x][y][move];

    int &ans = DP[x][y][move];
    ans = 0;
    
    //Explore possible directions
    for(int i = 0; i < 6; i++){
        ans += solve(x + dx[i], y + dy[i], move-1);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int num;
        cin >> num;
        //Reset every time
        memset(DP, -1, sizeof(DP));
        cout << solve(14, 14, num) << "\n";
    }
    
}
