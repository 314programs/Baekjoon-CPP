#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    int ans = 0;

    stack<int> num_s;
    //Multiplier for string
    stack<int> multi_s;
    //This will be used to keep track of length of string inside the brackets
    stack<int> add_s;

    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if(ch >= '0' && ch <= '9'){
            if(multi_s.empty()){
                //Add to the length of string outside brackets
                if(s[i+1] != '(') ans++;
                num_s.push(ch - '0');
            }
            else{
                //Add to the length of string inside brackets
                if(s[i+1] != '(') add_s.top()++;
                num_s.push(ch - '0');
            }
        }
        //New multiplication
        else if(ch == '('){
            multi_s.push(num_s.top());
            add_s.push(0);
        }
        //End of multiplication, multiply length of string inside by multiplier
        else if(ch == ')'){
            int multi = multi_s.top();
            multi_s.pop();
            int add = add_s.top();
            add_s.pop();
            
            //If stack is empty, it means that it has exited brackets, so it can be added to the answer
            if(multi_s.empty()){
                ans += multi * add;
            }
            else{
                add_s.top() += multi * add;
            }
        }
    }

    cout << ans;

}
