#include <bits/stdc++.h>
using namespace std;

int main(void){
    //Faster input
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int testcase;
    string str;
    cin >> testcase;
    //To ignore \n from input
    cin.ignore();

    while(testcase--){
        getline(cin, str);
        str += '\n';
        stack<char> stack_;
        
        //New type of for loop, just like python(for item in stack:)
        for(char ch: str){
            if(ch == ' ' || ch == '\n'){
                while(!stack_.empty()){
                    //Pop from stack to print it in reverse
                    cout << stack_.top();
                    stack_.pop();
                }
                cout << ch;
            }
            else{
                stack_.push(ch);
            }

        }
        
    }   
}
