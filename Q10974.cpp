#include <bits/stdc++.h>
using namespace std;

int num_list[8];
int check[9];

void backtrack(int num, int index_){
    if(index_ == num){
        for(int i = 0; i < num; i++){
            cout << num_list[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= num; i++){
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

    backtrack(list_len, 0);
    
}
