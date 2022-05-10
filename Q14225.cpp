#include <bits/stdc++.h>
using namespace std;

vector<int> store_list;
int store_num[2000001];
int list_size;
int ans = 0;

void backtrack_(vector<int> & numbers, int idx, int count_){
    if(idx == list_size){
        store_num[count_] = 1;
        return;
    }

    backtrack_(numbers, idx+1, count_ + numbers[idx]);
    backtrack_(numbers, idx+1, count_);

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> list_size;

    vector<int> num_list(list_size);
    for(int i = 0; i < list_size; i++){
        cin >> num_list[i];
    }

    memset(store_num, 0, sizeof(store_num));
    backtrack_(num_list, 0, 0);

    for(int i = 1; i < 2000001; i++){
        if(store_num[i] == 0){
            cout << i;
            break;
        }
    }

}

