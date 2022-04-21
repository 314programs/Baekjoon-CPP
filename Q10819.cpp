#include <bits/stdc++.h>
using namespace std;

int num_list[8];
int value_list[8];
int check[9];
int max_ = 0;

void backtrack(int num, int index_){
    if(index_ == num){
        int temp_max = 0;
        for(int i = 0; i < num-1; i++){
            temp_max += abs(value_list[num_list[i]] - value_list[num_list[i+1]]);
        }
        max_ = max(max_, temp_max);
        return;
    }

    for(int i = 0; i < num; i++){
        if(check[i] != -1){
            check[i] = -1;
            num_list[index_] = i;
            backtrack(num, index_+1);
            check[i] = 0;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int list_len;
    cin >> list_len;

    for(int i = 0; i < list_len; i++){
        cin >> value_list[i];
    }

    backtrack(list_len, 0);
    cout << max_;
    
}
