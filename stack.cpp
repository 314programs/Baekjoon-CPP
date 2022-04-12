#include <bits/stdc++.h>
using namespace std;

struct Stack{
    int data[10000];
    int size;

    Stack(){
        size = 0;
    }

    void push(int data_){
        data[size] = data_;
        size++;
    }
    void pop(){
        data[size] = 0;
        size--;
    }
    int size_(){
        return size;
    }
    bool empty(){
        if(size == 0){
            return true;
        }
        else{
            return false;
        }
    }
    int top(){
        return data[size-1];
    }

};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int commends;
    cin >> commends;

    Stack stack_;

    while(commends--){
        string commend;
        cin >> commend;
        if(commend == "push"){
            int num;
            cin >> num;
            stack_.push(num);
            
        }
        else if(commend == "pop"){
            if(stack_.empty()){
                cout << "-1\n";
            }
            else{
                cout << stack_.top() << "\n";
                stack_.pop();
            }
        }
        else if(commend == "size"){
            cout << stack_.size_() << "\n";
        }
        else if(commend == "empty"){
            if(stack_.empty()){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }
        }
        else if(commend == "top"){
            if(stack_.empty()){
                cout << "-1\n";
            }
            else{
                cout << stack_.top() << "\n";
            }
        }
    }
}
