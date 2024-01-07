#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int a_, b_, c_;
    cin >> a_ >> b_ >> c_;
    int sum_ = a_ + b_ + c_;

    bool check[1501][1501];
    memset(check, false, sizeof(check));
    
    //Check initially if it can be divided by 3
    if(sum_ % 3 != 0){
        cout << 0;
        return 0;
    }

    queue<pair<int, int>> q_;
    q_.push(make_pair(a_, b_));
    
    //DFS with only 2 variables, since other one can be found using sum_
    while(!q_.empty()){
        int x_ = q_.front().first;
        int y_ = q_.front().second;
        q_.pop();

        if(check[x_][y_] == true) continue;
        check[x_][y_] = true;

        int temp[3] = {x_, y_, sum_ - x_ - y_};

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(temp[i] < temp[j]){
                    int new_list[3] = {x_, y_, sum_ - x_ - y_};
                    new_list[i] += temp[i];
                    new_list[j] -= temp[i]; 
                    q_.push(make_pair(new_list[i], new_list[j]));
                }
            }
        }
    }
    
    //Only case when they are equal
    if(check[sum_/3][sum_/3] == true){
        cout << 1;
    }
    else{
        cout << 0;
    }


}


 
