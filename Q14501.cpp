//May try to solve this using dp
#include <bits/stdc++.h>
using namespace std;

int days_taken[15];
int profit[15];
int sessions;
int max_ = 0;

void backtrack(int day, int profit_){
    if(day == sessions){
        max_ = max(profit_, max_);
        return;
    }
    else if(day > sessions){
        return;
    }
    backtrack(day+1, profit_);
    backtrack(day + days_taken[day], profit_ + profit[day]);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    
    cin >> sessions;

    memset(profit, 0, sizeof(profit));

    for(int i = 0; i < sessions; i++){
        cin >> days_taken[i] >> profit[i];
    }

    backtrack(0, 0);
    cout << max_;
    
    
}

