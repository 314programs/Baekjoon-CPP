//Back to the basics...

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

struct Queue{
    int queue[2000000];
    int begin;
    int end;

    Queue(){
        begin = 0;
        end = 0;
    }

    void push(int data){
        queue[end] = data;
        end++;
    }

    void pop(){
        queue[begin] = 0;
        begin++;
    }
    
    int size(){
        return end-begin;
    }

    bool empty(){
        if(begin == end) return true;
        return false;
    }

    int front(){
        return queue[begin];
    }

    int back(){
        return queue[end-1];
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int tc;
    cin >> tc;
    Queue q;

    while(tc--){
        string c;
        cin >> c;

        if(c == "push"){
            int i;
            cin >> i;
            q.push(i);
        }
        else if(c == "pop"){
            if(!q.empty()){
                cout << q.front() << "\n";
                q.pop(); 
            }
            else cout << -1 << "\n";
        }
        else if(c == "size"){
            cout << q.size() << "\n";
        }
        else if(c == "empty"){
            cout << q.empty() << "\n";
        }
        else if(c == "front"){
            if(!q.empty()) cout << q.front() << "\n";
            else cout << "-1\n";
        }
        else{
            if(!q.empty()) cout << q.back() << "\n";
            else cout << "-1\n";
        }
    }
}
