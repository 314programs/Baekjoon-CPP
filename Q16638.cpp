#include <bits/stdc++.h>
using namespace std;

int ans = -2147483647;
int visited[12];

struct num{
    int num;
    char op;
};

void solve(int idx, int op_num, vector<num> numbers){
    if(idx == op_num){
        int temp = 0;
        for(int i = 1; i < op_num; i++){
            if(visited[i] == 1){
                //ith number will be kept
                //Previous number will be changed to ?, to mark that it has been calculated
                if(numbers[i].op == '+') numbers[i].num += numbers[i-1].num;
                if(numbers[i].op == '-') numbers[i].num = numbers[i-1].num - numbers[i].num;
                if(numbers[i].op == '*') numbers[i].num *= numbers[i-1].num;

                numbers[i].op = numbers[i-1].op;
                numbers[i-1].op = '?';
            }
        }

        vector<num> n_nums;
        //Remove the numbers already calculated
        for(auto ch: numbers){
            if(ch.op != '?') n_nums.push_back(ch);
        }

        int n_num_len = n_nums.size();
        //Calculate multiplication (they stack)
        for(int i = 0; i < n_num_len; i++){
            while(n_nums[i].op == '*'){
                if(i >= n_num_len) break;
                n_nums[i].op = n_nums[i-1].op;
                n_nums[i].num *= n_nums[i-1].num;
                n_nums[i-1].op = '?';
                i++;
            }
        }
        
        //Calculate remaining numbers
        for(auto ch: n_nums){
            if(ch.op == '+') temp += ch.num;
            if(ch.op == '-') temp -= ch.num;
        }
        
        ans = max(ans, temp);
        return;
    }
    
    //Make all possible permutations
    if(idx >= 1 && visited[idx-1] == 0){
        visited[idx] = 1;
        solve(idx+1, op_num, numbers);
    }
    visited[idx] = 0;
    solve(idx+1, op_num, numbers);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int len_;
    cin >> len_;

    string equation;
    cin >> equation;
    
    int equ_size = equation.length();
    vector<num> numbers((equ_size/2)+1);
    
    //Add numbers to list in form of operator, number
    //First number has operator of +
    numbers[0] = {equation[0] - '0', '+'};
    //i < equ_size + 2 made error
    for(int i = 1, idx = 1; i < equ_size; i += 2, idx++){
        numbers[idx] = {equation[i+1] - '0', equation[i]};
    }

    memset(visited, 0, sizeof(visited));
    solve(0, (equ_size/2)+1, numbers);
    cout << ans;
}
