#include <bits/stdc++.h>
using namespace std;

int visited[9];
int ans = -100000000;

void solve(int operator_count, int idx, vector<int> nums, vector<char> operations){
    if(idx == operator_count){
        //Firstly combine in a form: ans + 0
        for(int i = 0; i < operator_count; i++){
            if(visited[i] == 1){
                if(operations[i] == '+') nums[i] += nums[i+1] ;
                if(operations[i] == '-') nums[i] = nums[i] - nums[i+1];
                if(operations[i] == '*') nums[i] *= nums[i+1]; 

                nums[i+1] = 0;
                operations[i] = '+';
            }
        }
        //Work out ans by pushing result to back
        for(int i = 0; i < operator_count; i++){
            if(operations[i] == '+') nums[i+1] += nums[i];
            if(operations[i] == '-') nums[i+1] = nums[i] - nums[i+1];
            if(operations[i] == '*') nums[i+1] *= nums[i]; 
        }
        ans = max(ans, nums.back());
        return;
    }

    //If statement to prevent overlap of brackets
    if(idx == 0 || visited[idx-1] == 0){
        visited[idx] = 1;
        solve(operator_count, idx+1, nums, operations);
    }
    visited[idx] = 0;
    solve(operator_count, idx+1, nums, operations);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int equation_len;
    string equation;

    cin >> equation_len;
    cin.ignore();
    getline(cin, equation);

    vector<int> num_list;
    vector<char> operations_list;
    
    //Separate numbers and operators
    for(auto ch: equation){
        if(ch == '+' || ch == '-' || ch == '*'){
            operations_list.push_back(ch);
        }
        else{
            num_list.push_back(ch - '0');
        }
    }

    int operator_count = operations_list.size();
    solve(operator_count, 0, num_list, operations_list);
    memset(visited, 0, sizeof(visited));

    cout << ans;
}
