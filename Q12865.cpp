//Knapsack... DP...
//I forgot these algorithms, so doing it for revision
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int object_cnt, max_weight;
    cin >> object_cnt >> max_weight;
    
    //Always start adding values from index 1 during DP
    int value[object_cnt+1];
    int weight[object_cnt+1];

    for(int i = 1; i <= object_cnt; i++){
        cin >> weight[i] >> value[i];
    }
    int DP[object_cnt+1][max_weight+1];
    memset(DP, 0, sizeof(DP));
    
    //For each item
    for(int i = 1; i <= object_cnt; i++){
        //Until max_weight
        for(int j = 1; j <= max_weight; j++){
            DP[i][j] = DP[i-1][j];
            //If current item can fit in, find maximum between DP[i][j] and DP[i-1][j - weight[i]] + value[i]
            if(j - weight[i] >= 0){
                DP[i][j] = max(DP[i][j], DP[i-1][j - weight[i]] + value[i]);
            }
        }
    }
    
    cout << DP[object_cnt][max_weight];

}
