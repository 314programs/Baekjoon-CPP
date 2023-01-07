#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int testcase;
    string str;
    cin >> testcase;
    cin.ignore();

    while(testcase--){
        getline(cin, str);
        //Using stack
        stack<char> s;

        for(char ch: str){
            if(ch == '('){
                //Find if its a correct parenthesis string by matching values
                s.push(')');
            }
            else{
                if(s.empty()){
                    //Push any value so that the program can print "No"
                    s.push('.');
                    break;
                }
                s.pop();
            }
        }

        if(s.empty()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        
    }   
}
