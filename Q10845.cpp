#include <bits/stdc++.h>
using namespace std;

//Trying to make a queue
struct Queue{
    int data[10000];
    int start, end;

    Queue(){
        start = 0;
        end = 0;
    }

    void push(int data_){
        data[end] = data_;
        end +=1;
    }

    void pop(){
        data[start] = 0;
        start += 1;
    }

    int size(){
        return end - start;
    }

    bool empty(){
        if(size() == 0){
            return true;
        }
        else{
            return false;
        }
    }

    int front(){
        return data[start];
    }

    int back(){
        return data[end-1];
    }

};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int commends;
    cin >> commends;
    Queue q;

    while(commends--){
        string commend;
        cin >> commend;
        if(commend == "push"){
            int num;
            cin >> num;
            q.push(num);
        }
        else if(commend == "pop"){
            if(q.empty()){
                cout << "-1\n";
            }
            else{
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(commend == "size"){
            cout << q.size() << "\n";
        }
        else if(commend == "empty"){
            if(q.empty()){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }
        }
        else if(commend == "front"){
            if(!q.empty()){
                cout << q.front() << "\n";
            }
            else{
                cout << "-1\n";
            }
            
        }
        else if(commend == "back"){
            if(!q.empty()){
                cout << q.back() << "\n";
            }
            else{
                cout << "-1\n";
            }
            
        }
        
    }
}
