#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    //To store numbers of the list
    vector<int> store(n);
    //To store answers, reset these to -1 so if they don't can changed they print -1
    vector<int> answer_(n);
    //To store indexs that did not find the biggest number on the right
    stack<int> s;

    s.push(0);

    for(int i = 0; i < n; i++){
        //Storing
        cin >> store[i];
        answer_[i] = -1;
    }
    
    for(int i = 1; i < n; i++){
        //While loop to see if right biggest number can be found
        while(true){
            if(!s.empty() && store[s.top()] < store[i]){
                answer_[s.top()] = store[i];
                s.pop();
            }
            else{
                break;
            }
        }
        s.push(i);
    }
     
    //Print
    for(int i = 0; i < n; i++){
        cout << answer_[i] << " ";
    }
    
    
}
