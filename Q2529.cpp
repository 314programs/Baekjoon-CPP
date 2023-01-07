//332ms
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

//0ms!
#include <bits/stdc++.h>
using namespace std;

int length_;
char brackets[9];
int visited[10];

int numbers[10];
int small[10] = {0,1,2,3,4,5,6,7,8,9};
int big[10] = {9,8,7,6,5,4,3,2,1,0};

bool check(int first_, int second_, char bracket){
    if(bracket == '<' && first_ < second_) return true;
    if(bracket == '>' && first_ > second_) return true;
    return false;
}

string backtrack(int idx, int * numlist){
    if(idx == length_ + 1){
        string temp = "";
        for(int i = 0; i < length_ + 1; i++){
            temp += numlist[numbers[i]] + '0';
        }
        return temp;
    }

    for(int i = 0; i < length_ + 1; i++){
        if(visited[i] == -1 && (idx == 0 || check(numlist[numbers[idx-1]], numlist[i], brackets[idx-1]))){
            visited[i] = 0;
            numbers[idx] = i;
            string temp = backtrack(idx+1, numlist);
            if(temp != ""){
                return temp;
            }
            visited[i] = -1;
        }
    }

    return "";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> length_;
    for(int i = 0; i < length_; i++){
        cin >> brackets[i];
    }

    memset(visited, -1, sizeof(visited));
    cout << backtrack(0, big) << "\n";
    memset(visited, -1, sizeof(visited));
    cout << backtrack(0, small);

}


