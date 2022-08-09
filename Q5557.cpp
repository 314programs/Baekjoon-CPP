#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    long long DP[100][21];
    memset(DP, 0, sizeof(DP));

    int num_cnt;
    cin >> num_cnt;

    vector<int> nums(num_cnt);
    for(int i = 0; i < num_cnt; i++){
        cin >> nums[i];
    }
    
    //Starting number
    DP[0][nums[0]] = 1;
    for(int i = 0; i < num_cnt - 2; i++){
        for(int j = 0; j <= 20; j++){
            //What other numbers can be made
            if(DP[i][j] != 0){
                if(j + nums[i+1] <= 20) DP[i+1][j + nums[i+1]] += DP[i][j];
                if(j - nums[i+1] >= 0) DP[i+1][j - nums[i+1]] += DP[i][j];
            }
        }
    }

    cout << DP[num_cnt-2][nums[num_cnt-1]];
}
