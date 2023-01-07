#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int case_cnt;
    cin >> case_cnt;
    
    //Get DP values first
    int DP[10001];
    memset(DP, 0, sizeof(DP));

    DP[0] = 1;
    int nums[3] = {1,2,3};
    
    //For all numbers up to 10000
    for(int j = 0; j < 3; j++){
        for(int i = 1; i <= 10000; i++){
            //Add on previous value
            if(i - nums[j] >= 0){
                DP[i] += DP[i - nums[j]];
            }
        }
    }

    while(case_cnt--){
        int num;
        cin >> num;
        cout << DP[num] << "\n";
    }  

}
