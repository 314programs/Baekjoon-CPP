#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string sentence;
    bool in_tag = false;
    stack<char> reverse;
    getline(cin, sentence);
    sentence += ' ';

    for(auto ch: sentence){
        //(If not in tag?) ? put into reversing stack or print reverse stack : print the tag;
        if(!in_tag){
            //Both are used to end the word
            if(ch == ' ' || ch == '<'){
                while(!reverse.empty()){
                    cout << reverse.top();
                    reverse.pop();
                }
                cout << ch;
            }
            else{
                reverse.push(ch);
            }
        }
      
        else{
            cout << ch;
        }
        
        //Mark the start and end of brackets at the end of the loop so that the if function above executes properly
        if(ch == '<'){
            in_tag = true;
        }
        else if(ch == '>'){
            in_tag = false;
        }
    }
    
}
