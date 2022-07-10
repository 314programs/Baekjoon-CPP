#include <bits/stdc++.h>
using namespace std;

int visited[1001];

//Backracking to find all possible numbers
int solve(int idx, int len_, int sum_, int last){
    int ans = 0;
    vector<int> a = {1,5,10,50};
    if(idx == len_){
        if(visited[sum_] == 1) return 0;

        visited[sum_] = 1;
        return 1;
    }

    for(int i = 0; i < 4; i++){
        //Must be bigger or equal to last number to avoid repetition
        if(last <= a[i]) ans += solve(idx+1, len_, sum_ + a[i], a[i]);
    }
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int len_;
    cin >> len_;

    memset(visited, 0, sizeof(visited));
    cout << solve(0, len_, 0, 0);

}
