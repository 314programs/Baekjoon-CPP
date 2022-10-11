#include <bits/stdc++.h>
using namespace std;

int matrix_list[500][2];
int DP[500][500];

//Similar to merging files
int solve(int start, int end){
    if(DP[start][end] != -1) return DP[start][end];
    if(start == end){
        return 0;
    }
    else if(start + 1 == end){
        //Always use memoization
        return DP[start][end] = matrix_list[start][0] * matrix_list[start][1] * matrix_list[end][1];
    }
    int ans = -1;
    for(int i = start; i < end; i++){ 
        int temp = solve(start, i) + solve(i+1, end);
        //Value needed when adding these two values together as mentioned in the question
        temp += matrix_list[start][0] * matrix_list[i][1] * matrix_list[end][1];
        if(ans == -1 || temp < ans) ans = temp;
    }
    DP[start][end] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(DP, -1, sizeof(DP));
    int matrix_cnt;
    cin >> matrix_cnt;

    for(int i = 0; i < matrix_cnt; i++){
        cin >> matrix_list[i][0] >> matrix_list[i][1];
    }

    cout << solve(0, matrix_cnt-1);

}
