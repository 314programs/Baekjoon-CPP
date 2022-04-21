#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    char word[600000];
    int commends;
    cin >> word;
    cin >> commends;
    //Make length variable first so the loop doesn't keep measuring length
    int length_ = strlen(word);
    stack<char> right, left;
    
    for(int i = 0; i < length_; i++){
        left.push(word[i]);
    }

    while(commends--){
        char commend;
        cin >> commend;
        if(commend == 'L'){
            if(!left.empty()){
                right.push(left.top());
                left.pop();
            }
        }

        else if(commend == 'D'){
            if(!right.empty()){
                left.push(right.top());
                right.pop();
            }
            
        }

        else if(commend == 'P'){
            char letter;
            cin >> letter;
            left.push(letter);
        }
        
        else if(commend == 'B'){
            if(!left.empty()){
                left.pop();
            }
        }

    }

    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }

    while(!right.empty()){
        cout << right.top();
        right.pop();
    }


}
