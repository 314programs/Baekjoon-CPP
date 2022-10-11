#include <bits/stdc++.h>
using namespace std;

int DP[2000][2000];
int num_list[2001];

int solve(int i, int j){
    if(i == j){
        return 1;
    }
    else if(j - i == 1){
        if(num_list[i] == num_list[j]) return DP[i][j] = 1;
        else return 0;
    }

    if(DP[i][j] >= 0) return DP[i][j];
    if(num_list[i] != num_list[j]){
        return DP[i][j] = 0;
    }
    else return DP[i][j] = solve(i + 1, j - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(DP, -1, sizeof(DP));
    int list_len;
    cin >> list_len;

    for(int i = 1; i <= list_len; i++){
        cin >> num_list[i];
    }
    
    int q_cnt;
    cin >> q_cnt;

    while(q_cnt--){
        int start, end;
        cin >> start >> end;
        cout << solve(start, end) << "\n";
    }


}
