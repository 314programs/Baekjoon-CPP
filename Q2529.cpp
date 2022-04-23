#include <bits/stdc++.h>
using namespace std;

int bracket_num;
char brackets[10];
bool check[10];

string min_ = "9999999999";
string max_ = "0";

bool check_match(string nums){
    for(int i = 0; i < bracket_num; i++){
        if(brackets[i] == '<'){
            if((int)nums[i] > (int)nums[i+1]) return false;
        }
        else if(brackets[i] == '>'){
            if((int)nums[i] < (int)nums[i+1]) return false;
        }
    }
    return true;
}


void backtrack(int index_, string nums){
    if(index_ == bracket_num+1 && check_match(nums) == true){
        if(stoll(nums) < stoll(min_)){
            min_ = nums;
        }
        if(stoll(nums) > stoll(max_)){
            max_ = nums;
        }
        return;
    }
    for(int i = 0; i <= 9; i++){
        if(check[i] == false){
            check[i] = true;
            backtrack(index_ + 1, nums + to_string(i));
            check[i] = false;
        }
    }

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> bracket_num;

    for(int i = 0; i < bracket_num; i++){
        cin >> brackets[i];
    }

    backtrack(0, "");

    cout << max_ << "\n" << min_;

    
}

