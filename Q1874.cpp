#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int testcase;
    //Store it in a string and print later
    string ans = "";
    int num;
    int last_num = 0;
    cin >> testcase;
    cin.ignore();
    stack<int> s;

    while(testcase--){
        cin >> num;

        if(num > last_num){
            while(last_num < num){
                s.push(++last_num);
                ans += '+';
            }
            s.pop();
            ans += '-';
        }
        else{
            bool found = false;
            if(!s.empty()){
                //Get the number on top of the function
                int top_ = s.top();
                s.pop();
                ans += '-';
                //If the top number is not the number wanted, it is impossible
                if(top_ == num){
                    found = true;
                }
            }

            if(!found){
                cout << "NO";
                return 0;
            }
        }
        
    }   

    for(auto ch:ans){
        cout << ch << "\n";
    }

    return 0;
}
