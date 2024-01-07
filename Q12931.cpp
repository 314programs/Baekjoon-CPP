#include <bits/stdc++.h>
using namespace std;

int list_len;

bool check_even(vector<int> & num_list){
    for(auto ch: num_list){
        if(ch != 0 && ch%2 == 1) return false; 
    }
    return true;
}

//Make all numbers even... then divide and subtract remainder
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> list_len;

    int movement = 0;

    vector<int> num_list(list_len);
    vector<int> needed(list_len);
    for(int i = 0; i < list_len; i++){
        cin >> num_list[i];
        needed[i] = 0;
    }

    while(num_list != needed){

        if(check_even(num_list) == true){
            for(int i = 0; i < list_len; i++){
                num_list[i] /= 2;
            }
            movement++;
        }
        else{
            for(int i = 0; i < list_len; i++){
                if(num_list[i]%2 == 1){
                    num_list[i]--;
                    movement++;
                }
            }
        }   
    }

    cout << movement;
}
