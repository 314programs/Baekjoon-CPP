#include <bits/stdc++.h>
using namespace std;

long long num_list[10];
long long value_list[10][10];
int check[10];
long long min_ = 10000000001;

void backtrack(int num, int index_){
    if(index_ == num){
        long long temp_min = 0;
        for(int i = 0; i < num-1; i++){
            int temp = value_list[num_list[i]][num_list[i+1]];
            if(temp == 0){
                return;
            }
            temp_min += value_list[num_list[i]][num_list[i+1]];
        }
        temp_min += value_list[num_list[num-1]][num_list[0]];
        min_ = min(min_, temp_min);
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
        for(int j = 0; j < list_len; j++){
            cin >> value_list[i][j];
            if(i != j && value_list[i][j] == 0){
                value_list[i][j] = 10000000001;
            }
        }
    }

    backtrack(list_len, 0);
    cout << min_;
    
}
