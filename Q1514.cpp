#include <bits/stdc++.h>
using namespace std;

int n;
string s1, s2;
int DP[100][10][10];
//Number of turns required, clockwise or anti-clockwise
int turn[10] = {0,1,1,1,2,2,2,1,1,1};

//Current, next
int solve(int idx, int t1, int t2){
    //Memoization
    if(idx == n) return 0;
    if(DP[idx][t1][t2] != -1) return DP[idx][t1][t2];
    
    //Current number
    int current = ((s1[idx] - '0') + t1)%10;
    int to = s2[idx] - '0';

    for(int three = 0; three < 10; three++){
        for(int two = 0; two < 10; two++){
            //Current number + spins
            int from = (current + two + three)%10;
            int one = (to-from+10)%10;
            
            //Use turns array to calculate value
            int cost = turn[one] + turn[two] + turn[three];
            //Calculate the turns for the next, and next next numbers
            cost += solve(idx+1, (t2 + two + three)%10, three);
            //Update DP value
            if(DP[idx][t1][t2] == -1 || cost < DP[idx][t1][t2]){
                DP[idx][t1][t2] = cost;
            }
        }
    }
    
    return DP[idx][t1][t2];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    cin >> s1 >> s2;
    memset(DP, -1, sizeof(DP));
    cout << solve(0, 0, 0);

}
