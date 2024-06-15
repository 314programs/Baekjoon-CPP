#include <bits/stdc++.h>
using namespace std;

int num_list[13];
int value_list[14];
int check[13];
int max_ = 0;

void backtrack(int num, int index_){
    if(index_ == 6){
        int temp_max = 0;
        for(int i = 0; i < 6; i++){
            cout << value_list[num_list[i]] << " ";
        }
        cout << "\n";
        max_ = max(max_, temp_max);
        return;
    }

    for(int i = 0; i < num; i++){
        if(check[i] != -1 && (index_ == 0 || value_list[num_list[index_-1]] < value_list[i])){
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

    while(true){
        int list_len;
        cin >> list_len;

        
        if(list_len == 0){
            break;
        }
        
        memset(check, 0, sizeof(check));
        for(int i = 0; i < list_len; i++){
            cin >> value_list[i];
        }

        backtrack(list_len, 0);
        cout << "\n";
    }
    
    
}
