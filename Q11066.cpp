#include <bits/stdc++.h>
using namespace std;

long long DP[500][500];

long long solve(vector<int> files, int start, int end){
    if(DP[start][end] != -1) return DP[start][end];
    //No cost
    if(end == start){
        return DP[start][end] = 0;
    }
    //Cost of 2 costs combined
    else if(end - start == 1){
        return DP[start][end] = files[start] + files[end];
    }

    long long ans = DP[start][end];
    long long sum_ = 0;
  
    //Needs to use summed up value in the calculation
    for(int i = start; i <= end; i++){
        sum_ += files[i];
    }
    
    //Separate files
    for(int i = start; i < end; i++){
        int temp = solve(files, start, i) + solve(files, i+1, end) + sum_;
        //Get minimum value
        if(ans == -1 || ans > temp){
            ans = temp;
        }
    }
    DP[start][end] = ans;
    return ans;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int test_case;
    cin >> test_case;

    while(test_case--){
        memset(DP, -1, sizeof(DP));
        int file_cnt;
        cin >> file_cnt;

        vector<int> files(file_cnt);
        for(int i = 0; i < file_cnt; i++){
            cin >> files[i];
        }
        
        cout << solve(files, 0, file_cnt-1) << "\n";

    }

}
