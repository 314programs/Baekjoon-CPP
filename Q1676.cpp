#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int num;
    int zero_num = 0;
    cin >> num;

    for(int i = 1; i <= num; i++){
        //Could make a for loop here, but since question has small range, no need
        if(i%5 == 0){
            zero_num += 1;
        }
        if(i%25 == 0){
            zero_num += 1;
        }
        if(i%125 == 0){
            zero_num += 1;
        }
    }
    cout << zero_num;
    
}
