#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string num;
    getline(cin, num);

    bool is_zero = false;
    int sum_ = 0;
    
    //0 is for divisible by 2 and 5
    for(auto ch : num){
        if(ch - '0' == 0) is_zero = true;
        sum_ += ch - '0';
    }
    
    //if sum of all digits are divisible by 3, it can be divided by 3
    if(sum_%3 == 0 && is_zero){
        sort(num.begin(), num.end());
        reverse(num.begin(), num.end());
        cout << num;
    }
    else{
        cout << -1;
    }

}
