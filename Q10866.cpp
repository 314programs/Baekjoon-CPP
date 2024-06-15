#include <bits/stdc++.h>
using namespace std;

//Will try making deque struct later
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int commends;
    deque<int> dq;
    cin >> commends;
    cin.ignore();

    while(commends--){
        string commend;
        cin >> commend;

        if(commend == "push_front"){
            int num;
            cin >> num;
            dq.push_front(num);
        }
        else if(commend == "push_back"){
            int num;
            cin >> num;
            dq.push_back(num);
        }
        else if(commend == "pop_front"){
            if(!dq.empty()){
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            else{
                cout << "-1\n";
            }
        }
        else if(commend == "pop_back"){
            if(!dq.empty()){
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            else{
                cout << "-1\n";
            }
        }
        else if(commend == "size"){
            cout << dq.size() << "\n";
        }
        else if(commend == "empty"){
            if(dq.empty()){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }
        }
        else if(commend == "front"){
            if(!dq.empty()){
                cout << dq.front() << "\n";
            }
            else{
                cout << "-1\n";
            }
        }
        else if(commend == "back"){
            if(!dq.empty()){
                cout << dq.back() << "\n";
            }
            else{
                cout << "-1\n";
            }
        }

    }
    
}
