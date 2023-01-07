#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int testcase;
    cin >> testcase;

    string commend;
    int commend_num;
    int size_ = 20;

    int bit_ = 0;

    while(testcase--){
        cin >> commend;
        if(commend == "add"){
            cin >> commend_num;
            bit_ = (bit_ | (1 << (commend_num - 1)));
        }
        else if(commend == "remove"){
            cin >> commend_num;
            bit_ = (bit_ & ~(1 << (commend_num - 1)));
        }
        else if(commend == "check"){
            cin >> commend_num;
            int result = (bit_ & (1 << (commend_num - 1)));
            if(result){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }
        }
        else if(commend == "toggle"){
            cin >> commend_num;
            bit_ = (bit_ ^ (1 << (commend_num - 1)));
        }
        else if(commend == "all"){
            bit_ = (1 << size_) -1;
        }
        else if(commend == "empty"){
            bit_ = 0;
        }
    }
    
}

