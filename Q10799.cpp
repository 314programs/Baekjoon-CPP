#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string sentence;
    int stacks = 0;
    int total = 0;
    char prev = 'a';
    stack<int> s;
    getline(cin, sentence);

    for(auto ch: sentence){
        if(ch == '('){
            stacks += 1;
            s.push(')');
        }
        else{
            #Got slightly confused at this part
            if(prev == '('){
                stacks -= 1;
                total += stacks;
            }
            else{
                stacks -= 1;
                total += 1;
            }
            
            s.pop();
        }
        prev = ch;
    }

    cout << total;
    
}
