//Solving things the most difficult way...

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int n;
vector<int> operand;
vector<int> operators;
vector<int> equation;

int minimum = 2e9;
int maximum = -2e9;

map<int, int> m;

int operation(int oper, int n1, int n2){
    if(oper == 0){
        return n1 + n2;
    }
    else if(oper == 1){
        return n1 - n2;
    }
    else if(oper == 2){
        return n1 * n2;
    }
    else{
        return floor(n1 / n2);
    }
}

int calc(){
    stack<int> operands_stack;
    stack<int> operator_stack;
    operands_stack.push(operand[0]);

    for(int i = 1; i < n; i++){
        int cur_num = operand[i];
        int cur_op = equation[i-1];

        if(!operands_stack.empty() &&  m[cur_op] == 2){
            int s_num = operands_stack.top();
            operands_stack.pop();
            operands_stack.push(operation(cur_op, s_num, cur_num));
        }
        else{
            operands_stack.push(cur_num);
            operator_stack.push(cur_op);
        }
    }
    
    vector<int> oper_vec;
    vector<int> val_vec;
    while(!operator_stack.empty()){
        oper_vec.push_back(operator_stack.top());
        operator_stack.pop();
    }

    while(!operands_stack.empty()){
        val_vec.push_back(operands_stack.top());
        operands_stack.pop();
    }
    reverse(oper_vec.begin(), oper_vec.end());
    reverse(val_vec.begin(), val_vec.end());

    int ans = val_vec[0];
    for(int i = 1; i < val_vec.size(); i++){
        int cur_num = val_vec[i];
        int cur_op = oper_vec[i-1];
        ans = operation(cur_op, ans, cur_num);
    }

    return ans;
}

void solve(int idx){
    if(idx == n-1){
        int cur = calc();
        minimum = min(cur, minimum);
        maximum = max(cur, maximum);
        return;
    }

    //0: +, 1: -, 2: *, 3: /
    for(int i = 0; i < 4; i++){
        if(operators[i] > 0){
            equation[idx] = i;
            operators[i]--;
            solve(idx+1);
            operators[i]++;
        }
    }
}


int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> n;

    operand.resize(n);
    operators.resize(4);
    for(int i = 0; i < n; i++){
        cin >> operand[i];
    }

    m[0] = 1;
    m[1] = 1;
    m[2] = 2;
    m[3] = 2;

    equation.resize(n-1);
    for(int i = 0; i < 4; i++){
        cin >> operators[i];
    }
    solve(0);
    cout << maximum << "\n" << minimum;

}
