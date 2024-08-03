#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string num_2;
    //Make dictionary of values
    string mp[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    cin >> num_2;
    int size_ = num_2.size();
    
    //Exception for 0
    if(num_2[0] == '0'){
        cout << 0;
    }
    else{
        for(int i = 0; i < size_; i++){
            if(i == 0 && num_2[i]-'0' < 4){
                if(num_2[i] == '1'){
                    cout << "1";
                }
                if(num_2[i] == '2'){
                    cout << "10";
                }
                if(num_2[i] == '3'){
                    cout << "11";
                }
            }
            else{
                cout << mp[num_2[i]-'0'];
            }
        }
    }

}
