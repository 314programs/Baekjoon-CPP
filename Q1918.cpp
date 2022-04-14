#include <bits/stdc++.h>
using namespace std;

int main(void){
    string Equation;
    stack<char> s;
    map<char, int> value_;

    cin >> Equation;
    
    //Assign value to each of the operators
    value_['+'] = 1;
    value_['-'] = 1;
    value_['/'] = 2;
    value_['*'] = 2;

    for(auto ch: Equation){
        //If it is a character, print
        if((int)'A' <= (int)ch && (int)ch <= (int)'Z'){
            cout << ch;
        }
        //If it is an operator...
        else{
            //If opening bracket comes out, store it
            if(ch == '('){
                s.push('(');
            }
            //If a closing bracket comes out, keep popping and printing operators until the stored bracket opener comes out
            else if(ch == ')'){
                while(!s.empty() && s.top() != '('){
                    cout << s.top();
                    s.pop();
                }
                s.pop();
            }
            //While the top value of stack is smaller or equal to current value of operator, push the operator into the stack
            //Else run a while loop to pop and print operators
            else{
                while(!s.empty() && value_[s.top()] >= value_[ch]){
                    cout << s.top();
                    s.pop();
                }

                s.push(ch);
            }
        }
    }
    
    //Print remaining operators
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }


}
